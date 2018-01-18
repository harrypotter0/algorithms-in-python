for _ in range(int(input())):
    n = int(input())
    sum1 = 0
    sum2 = 0
    for z in range(n):
        p,q = map(int,raw_input().split())
        sum1+=p
        sum2+=q
    print(sum1-sum2)
