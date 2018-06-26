# !/usr/bin/env python
# coding=utf-8
import sys

def cal(val, mid, month):
    v = -val[0] * pow(1 + mid, month);
    for i in range(1, month + 1):
        v += val[i] * pow(1 + mid, month - i);
    return v 

def get_IRR(val, month):
    l, r = -1.0, 1.0  
    while (r - l > 1e-12):
        mid = (l + r) / 2
        if cal(val, mid, month) > 0.0:
            l = mid
        else:
            r = mid
    return l


if __name__ == '__main__':
    # begin
    open_file = open("../test.in", 'rU')
    sys.stdout = open("../test.out", 'w')
    input_parameters = open_file.read().split('\n')
    num_case = int(input_parameters[0])
    pos = 1
    for index in range(num_case):
        month = int(input_parameters[pos])
        pos += 1
        # init cost and profits
        val = [int(t) for t in input_parameters[pos].split(' ')]
        pos += 1
        print "Case #%d: %.12f" % (index + 1, get_IRR(val, month))