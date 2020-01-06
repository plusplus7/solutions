import math

ans = 0
r = 0
arrr = []
def geth(t):
    h = 0
    for i in range(0, len(t)):
        for j in range(i, len(t)):
            if max(t[i:j+1])-min(t[i:j+1]) == j-i:
                h = h + 1
    return h

def permutations(arr, position, end):
    global ans
    global r
    if position == end:
        arrr.append(geth(arr))
        ans = ans + geth(arr)

        r = r +1
    else:
        for index in range(position, end):
 
            arr[index], arr[position] = arr[position], arr[index]
            permutations(arr, position+1, end)
            arr[index], arr[position] = arr[position], arr[index]


t = [1, 2,3,4,5,6,7,8,9,10]
pr = 32
for i in range(2, 8):
    ans = 0
    arrr = []
    r = 0
    permutations(t[:i], 0, len(t[:i]))
    a = r*((i+i*i)/2)
    arrr.sort()
    pr = -1
    for i in arrr:
        if pr == i:
            continue
        cnt = 0
        for c in arrr:
            if c == i:
                cnt = cnt + 1
        pr = i
        print("-> ", cnt, i)

    print(ans,"/", a, a-ans)
    print("->", ans*10 - pr)
    pr = ans