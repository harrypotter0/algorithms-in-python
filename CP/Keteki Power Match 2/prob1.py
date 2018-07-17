import math

t = input()
while t>0:
    t = t-1
    s = raw_input()
    d = {}
    for i in range(len(s)):
        if s[i] not in d.keys():
            d[s[i]] = 1
        else:
            d[s[i]] += 1
    ans = math.factorial(len(s))
    # print(ans)
    for i in d.keys():
        p = math.factorial(d[i])
        ans /= p
        # print(p)
    print ans
