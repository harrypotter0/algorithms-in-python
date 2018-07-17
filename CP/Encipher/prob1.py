for __ in range(int(input())):
    n,m = map(int,raw_input().split())
    print(n/m+(1 if n%m>0 else 0))
