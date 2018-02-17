n = int(input())
arr = map(int,raw_input().split())
a=[]
f=0
j=0
for i in range(0,n):
    vec = arr[i]
    while j<n and vec!=n:
        if(arr[i] in a):
            # print(a)
            f=1
            break
        if(vec!=arr[vec-1]):
            vec=arr[vec-1]
        a.append(vec)
        j+=1
    print(a)
    if(f and len(a)==3): break
    del a[:]

# del lst[:]

# print(a)
if(f and len(a)==3):
     print("YES")
else:
     print("NO")


'''
5
2 4 5 1 3

5
4 2 1 3 5

5
4 1 2 3 5


5
5 5 5 5 1


'''
