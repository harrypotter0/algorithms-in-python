# !/usr/bin/env python
# coding=utf-8

import sys

MOD = 1000000007
# def number_case(a, b, n, k):
#     count = 0
#     for i in range(1, n + 1):
#         for j in range(1, n + 1):
#             if i == j:
#                 continue
#             if (fast_pow(i, a, k) + pow(j, b, k)) % k == 0:
#                 count += 1
#     return count

def number_case(a, b, n, k):
    # Only record 0~k-1 buckets
    a_dic = [0] * k
    b_dic = [0] * k
    drop = [0] * k
    res = 0
    i = 1
    while i <= min(n, k):
        # (i + k)^A % k == i^A % k
        # if i satisfies, then i + k, i + 2k.... satisfy condition.
        if n % k >= i:
            count = 1
        else:
            count = 0
        count += n / k
        if count == 0:
            continue    
        a_index = fast_pow(i, a, k)
        b_index = fast_pow(i, b, k)
        a_dic[a_index] += count
        b_dic[b_index] += count
        # when i = j
        if (a_index + b_index) % k == 0:
            # a_index or i % k, because they all less than k
            drop[a_index] += count
        i += 1
    for i in range(k):
        other = (k - i) % k
        res += a_dic[i] * b_dic[other]
        res -= drop[i]
    res %=  MOD
    return res


def fast_pow(x, y, n):
    # pow(x, y) % n
    ans, temp = 1, x
    while y > 0:
        if y % 2 == 1:
            ans = (ans * temp) % n
        temp = (temp * temp) % n
        y /= 2
    return ans % n

if __name__ == '__main__':
    # begin
    open_file = open("../test.in", 'rU')
    sys.stdout = open("../test.out", 'w')
    input_parameters = open_file.read().split('\n')
    num_case = int(input_parameters[0])
    pos = 1
    for index in range(num_case):
        temp = input_parameters[pos].split(' ')
        pos += 1
        a, b, n, k = long(temp[0]), long(temp[1]), long(temp[2]), int(temp[3])
        print "Case #%d: %d" % (index + 1, number_case(a, b, n, k))

