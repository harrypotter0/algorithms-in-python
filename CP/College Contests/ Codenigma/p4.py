a=[1,9]
# print a
mod=10**9+7
t=int(raw_input())
while t!=0:
    t=t-1
    n=int(raw_input())
    print (pow(2,n-1,mod)*(pow(4,n,mod)+pow(5,n,mod))%mod)
    # print (((pow(8,n,mod)+pow(10,n,mod)))%mod)/2

'''
2
1
2

9
82
'''
