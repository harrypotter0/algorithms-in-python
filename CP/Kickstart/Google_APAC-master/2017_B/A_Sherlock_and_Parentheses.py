# !/usr/bin/env python
# coding=utf-8

import sys

def number_parentheses(n):
    if n <= 1:
        return n
    return (n + 1) * n / 2


if __name__ == '__main__':
    # begin
    open_file = open("../test.in", 'rU')
    sys.stdout = open("../test.out", 'w')
    input_parameters = open_file.read().split('\n')
    num_case = int(input_parameters[0])
    pos = 1
    for index in range(num_case):
        temp = input_parameters[pos].split(' ')
        l, r = int(temp[0]), int(temp[1])
        pos += 1
        print "Case #%d: %d" % (index + 1, number_parentheses(min(l, r)))
