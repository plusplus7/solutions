a = 191
b = 31415926
i = 123
j = 456
print (int(str(i) + str(j)))

for i in range(1, a):
    for j in range(1, b):
        if i*j + i + j == int(str(i) + str(j)):
            print(i,j)
    if i%100 == 0:
        print ("=>", (i))
