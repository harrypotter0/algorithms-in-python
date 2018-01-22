import math
for kohli in range(input()):
    n,k,s = map(int,raw_input().split())
    if(n<k or (6*n<7*k and s>=7)):
        print("-1")
        continue
    c = int(math.ceil(s*1.0/(n*1.0/k*1.0)))
    print(c)


'''
2
16 2 10
50 48 7
'''
