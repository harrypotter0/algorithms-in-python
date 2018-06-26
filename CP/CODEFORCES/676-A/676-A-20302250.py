n = int(input())
a = list(map(int,input().split()))
print(max(len(a)-1-a.index(n),len(a)-1-a.index(1),a.index(n),a.index(1)))