

# !/usr/bin/env python
# coding=utf-8
import sys

if __name__ == '__main__':
    # begin
    open_file = open("../test.in", 'rU')
    sys.stdout = open("../test.out", 'w')
    input_parameters = open_file.read()
    num_case = int(input_parameters[0])
    for index in range(num_case):
        print "Case #%d: %d" % (index, index)