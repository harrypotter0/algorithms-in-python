# I love u, always have, wanna marry u :-)

t=input()
while(t!=0):
    n=int(input())
    arr=map(int,raw_input().split())
    k=int(input())
    ans=0
    num=arr[k-1]
    arr.sort()
    ans=arr.index(num)+1
    print ans
    t-=1
'''
if __name__ == '__main__':
    main()
'''
