def solve(N, A):
    T = N / 4
    count = [0, 0, 0, 0]
    for x in A: count[x] += 1
    if all(x <= T for x in count): return 0
    j = 0
    ans = N
    for i, x in enumerate(A):
        while j < len(A) and any(x > T for x in count):
            count[A[j]] -= 1
            j += 1
        if all(x <= T for x in count):
            ans = min(ans, j - i)
        count[A[i]] += 1
    return ans

N = int(raw_input())
A = []
S = raw_input()
for c in S:
    if c == 'A': A.append(0)
    elif c == 'C': A.append(1)
    elif c == 'T': A.append(2)
    else: A.append(3)


print solve(N, A)
