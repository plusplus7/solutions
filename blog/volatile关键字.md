    最近在看Linux的进程调度，其中进程描述符task_struct中有个变量state。这个变量是这样定义的：
    volatile long state;

    由于之前不了解volatile关键字的用法，所以这里对volatile深究了一下。

## **一. volatile关键字**

volatile是一个类型修饰符（type specifier）。

在程序设计中，尤其是在C语言、C++、C#和Java语言中，使用volatile关键字声明的变量或对象通常拥有和优化和（或）多线程相关的特殊属性。通常，volatile关键字用来阻止（伪）编译器对那些它认为变量的值不能“被代码本身”改变的代码上执行任何优化。 在C环境中，volatile关键字的真实定义和适用范围经常被误解，加之C++、C#和Java都从C中神秘地“继承”了volatile，在这些编程语言中，因此这些语言中volatile的用法和语义大相径庭。

## **二. 从比赛中引出问题**

 在正式ACM/ICPC比赛开始之前，参赛选手都会做一项测试OJ系统各项边界的工作，比如测试提交代码最大可以开多少的数组，能大概接受多少时间复杂度的算法...

比如：

    #include <stdio.h>
    int main()
    {
        int i;
        for (i=0; i<1000000000; i++);
        return 0;
    }

显然，这段程序是在测试OJ能不能接受$O(10^9)$的算法,提交OJ返回的信息（**Accept** or **Time Limit Exceed**）来判断能否接受。

通常情况下，这段代码提交上去都会被接受。

因为在大多数OJ系统中，OJ在用gcc编译代码时，会自动加上-O2优化。结果就是，代码第5行的for循环被编译器优化掉了，最后不会被真正执行。

这个情况在测试可以开多大数组中也会出现：编译器认为你开的数组没有被使用，所以就自动给优化了。

于是通常的解决办法是，在循环中加一些赋值或其他的操作，来防止编译器自动优化。

## **三. 从实例中分析问题**

编写Linux信号处理程序遇到的一个问题。

代码:

	#include <stdio.h>
	#include <signal.h>
	int a;
	void func(int signo)
	{
		printf("SIGNO: %d\n",signo);
		a=1;
		printf("%d\n",a);
	}
	int main()
	{
		a=0;
		signal(SIGINT,func);
		while (a != 1);
		return 0;
	}

这段程序设置进程接受到SIGINT信号（摁下ctrl+c）时的动作是调用func函数。

之后程序便进入一个循环，知道a的值被赋为1时，结束。

可以看看实际效果。

<img src="http://bcs.duapp.com/blogbuk/volatile.png"></img>

当使用gcc编译不开启O3编译优化选项时，程序执行效果和预想的效果是一样的。

当使用gcc编译开启O3编译优化选项时，摁下ctrl+c时，程序并没有终止，而是继续循环了下去...最后是发送SIGQUIT信号（摁下ctrl+\）才停止的。

使用gcc -S t.c命令生产t.s文件，t.s文件里面可以看到t.c通过gcc产生的汇编代码。
File t.s：

		.file	"t.c"
		.comm	a,4,4
		.section	.rodata
	.LC0:
		.string	"SIGNO: %d\n"
	.LC1:
		.string	"%d\n"
		.text
		.globl	func
		.type	func, @function
	func:
	.LFB0:
		.cfi_startproc
		pushl	%ebp
		.cfi_def_cfa_offset 8
		.cfi_offset 5, -8
		movl	%esp, %ebp
		.cfi_def_cfa_register 5
		subl	$24, %esp
		movl	8(%ebp), %eax
		movl	%eax, 4(%esp)
		movl	$.LC0, (%esp)
		call	printf
		movl	$1, a
		movl	a, %eax
		movl	%eax, 4(%esp)
		movl	$.LC1, (%esp)
		call	printf
		leave
		.cfi_restore 5
		.cfi_def_cfa 4, 4
		ret
		.cfi_endproc
	.LFE0:
		.size	func, .-func
		.globl	main
		.type	main, @function
	main:
	.LFB1:
		.cfi_startproc
		pushl	%ebp
		.cfi_def_cfa_offset 8
		.cfi_offset 5, -8
		movl	%esp, %ebp
		.cfi_def_cfa_register 5
		andl	$-16, %esp
		subl	$16, %esp
		movl	$0, a
		movl	$func, 4(%esp)
		movl	$2, (%esp)
		call	signal
		nop
	.L3:
		movl	a, %eax
		cmpl	$1, %eax
		jne	.L3
		movl	$0, %eax
		leave
		.cfi_restore 5
		.cfi_def_cfa 4, 4
		ret
		.cfi_endproc
	.LFE1:
		.size	main, .-main
		.ident	"GCC: (Ubuntu/Linaro 4.7.2-2ubuntu1) 4.7.2"
		.section	.note.GNU-stack,"",@progbits

第38行开始是main函数代码段。

可以看到第53行到第56行是while循环代码段。

第54行，把a传送到eax寄存器;

第55行，比较数值1和eax寄存器中保存的值，即a;

第56行，jne：若不相等则跳转到.L3;

所以在汇编代码中，这个while循环是老老实实地执行了的。

再使用gcc -S -O3 t.c -o t2.s 命令生产t2.s文件，t2.s文件里面可以看到t.c通过gcc并且经过O3编译优化之后产生的汇编代码。为了节省篇幅，就放从main之后的代码段。
File t2.s

	...
	main:
	.LFB26:
		.cfi_startproc
		pushl	%ebp
		.cfi_def_cfa_offset 8
		.cfi_offset 5, -8
		movl	%esp, %ebp
		.cfi_def_cfa_register 5
		andl	$-16, %esp
		subl	$16, %esp
		movl	$func, 4(%esp)
		movl	$2, (%esp)
		movl	$0, a
		call	signal
		cmpl	$1, a
		je	.L4
	.L6:
		jmp	.L6
		.p2align 4,,7
		.p2align 3
	.L4:
		xorl	%eax, %eax
		leave
		.cfi_restore 5
		.cfi_def_cfa 4, 4
		ret
		.cfi_endproc
	.LFE26:
		.size	main, .-main
		.comm	a,4,4
		.ident	"GCC: (Ubuntu/Linaro 4.7.2-2ubuntu1) 4.7.2"
		.section	.note.GNU-stack,"",@progbits

第15行，对比了a和1的大小；

第16行，je：相等则跳转到.L4。因为a=2，所以显然这里的跳转不会执行。

第18行，jmp：无条件跳转到L6。相当于是在不断地回跳，即死循环。

由此可知到，编译器并不知道a的值是会发生变化的。

## **四. 使用volatile解决问题**

volatile关键字就是要告诉编译器，这个变量时经常改变的，而且编译时不要进行代码优化，所以每次读写的时候都要到它所在的地址去读取。
如：

    volatile int a；


这样写，编译器就不会再盲目地把原来的那个循环“优化”
<im1g src="http://bcs.duapp.com/blogbuk/volatile2.jpg"/>