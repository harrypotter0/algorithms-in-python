# !/usr/bin/env python
# coding=utf-8

import sys
from itertools import permutations

# f(n) = n! - \sum f(i)*(n-i)!
# Then optimize dp from O(n^3) to O(n^2)

def permutation_sorting(n, m):
    perm = [0] * 5005
    f = [0] * 5005
    dp = [[0] * 3 for _ in range(5005)]
    # dp[x][0] = dp[x][0] + dp[x][1] + ...
    # dp[x][1] = dp[x][0]*2*0 + dp[x][1]*2*1 + ...
    # dp[x][2] = dp[x][0]*2*2 + dp[x][1]*1*2 + ...
    perm[0] = 1
    for i in range(1, n + 1):
        perm[i] = perm[i - 1] * i % m
        f[i] = perm[i]
        for j in range(1, i):
            f[i] = (f[i] - f[j] * perm[i - j] % m + m) % m
    dp[0][0], dp[0][1],  dp[0][2] = 1, 0, 0
    for i in range(1, n + 1):
        for j in range(1, i + 1):
            dp[i][0] = (dp[i][0] + dp[i - j][0] * f[j] % m) % m
            dp[i][1] = (dp[i][1] + (dp[i - j][0] * 2 + dp[i - j][1]) * f[j] % m) % m
            dp[i][2] = (dp[i][2] + (dp[i - j][2] + dp[i - j][1] + dp[i - j][0]) * f[j] % m) % m
    return dp[n][2]


if __name__ == '__main__':
    # begin
    open_file = open("../test.in", 'rU')
    sys.stdout = open("../test.out", 'w')
    input_parameters = open_file.read().split('\n')
    num_case = int(input_parameters[0])
    pos = 1
    for index in range(num_case):
        temp = input_parameters[pos].split(' ')
        n, m = int(temp[0]), int(temp[1])
        pos += 1
        print "Case #%d: %d" % (index + 1, permutation_sorting(n, m))
