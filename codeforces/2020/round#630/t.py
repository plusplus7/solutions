a = [2,3,5,7,11,13,17,19,23,29,31]

v = {}
for x in a:
    t = x
    while t <= 1000:
        v[t] = 1
        t+=x
        

print(len(v.keys()))
print(v)

def su(a,b):
    r = []
    for i in range(a,b):
        n = False #默认不是素数，如果是素数，跳出循环
        for j in range(2,i):
            if i%j == 0:
                n = True
                break
                
        if n == False:
            r.append(n)
    return r

print(len(su(1, 1000)))

for i in range(1, 779):
    if 779%i == 0:
        print(i)