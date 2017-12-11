# I love u, always have, wanna marry u :-)

def main():
    t=input()
    while t!=0:
        n=input()
        a=map(int,raw_input().split())
        a.sort()
        min1=a[1]-a[0]
        for i in range(2,n):
            num=a[i]-a[i-1]
            if(min1>num):
                min1=num
        print min1
        t-=1
if __name__ == '__main__':
    main()
