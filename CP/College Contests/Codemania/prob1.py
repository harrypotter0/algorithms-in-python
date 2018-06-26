import math
for __ in range(int(input())):
    n = int(raw_input())
    print(int(math.log(n+1,2))+(1 if math.log(n+1,2)>int(math.log(n+1,2)) else 0))
    # print(int(math.log(n+1,2)))
    # print(math.log(n+1,2))
