def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n-1)

for _ in range(int(raw_input())):
    final = 0
    s = raw_input()
    for i in range(0,len(s)):
        count = 0
        for j in range(i+1,len(s)):
            if (s[j]>s[i]):
                count = count+1
        final = final + count*factorial(len(s)-i-1)
    print final
