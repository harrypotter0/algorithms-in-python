# !/usr/bin/env python
# coding=utf-8
import sys

def robot_rock_band(n, k, band):

    return

if __name__ == '__main__':
    # begin
    open_file = open("../test.in", 'rU')
    sys.stdout = open("../test.out", 'w')
    input_parameters = open_file.read()
    num_case = int(input_parameters[0]).split('\n')
    pos = 1
    for index in range(num_case):
        n, k = map(int, input_parameters[pos].split(' '))
        pos += 1
        band = []
        for _ in range(4):
            for i in range(n):
                band.append(map(int, input_parameters[pos].split(' '))
            pos += 1
        print "Case #%d: %d" % (index + 1, robot_rock_band(n, k, band))