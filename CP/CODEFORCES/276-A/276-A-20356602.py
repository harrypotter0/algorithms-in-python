I=lambda:map(int,input().split())
n,k=I()
print(max((lambda a,b:a-max(0,b-k))(*I())for i in[0]*n))