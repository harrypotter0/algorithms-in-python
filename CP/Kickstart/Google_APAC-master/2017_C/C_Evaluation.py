# !/usr/bin/env python
# coding=utf-8
import sys

def Evaluation(expression, n):
    nodes = []; count = 0
    check = set(); has = set();
    for ex in expression:
        temp = ex.split('=')
        curr = [temp[0]]
        start = temp[1].index('(')
        end = temp[1].index(')')
        if start + 1 < end:
            rest = set(temp[1][start + 1: end].split(','))
            if curr[0] in rest:
                return 'BAD'
            curr.append(rest)
            check.add(temp[0])
        else:
            has.add(temp[0])
            count += 1
            continue
        nodes.append(curr)
    if count == 0:
        return 'BAD'
    for _ in range(len(nodes)):
        # n rounds pass
        for ex in nodes:
            if ex[1].issubset(has):
                has.add(ex[0])
    for t in check:
        if t in has:
            continue
        else:
            return 'BAD'
    return 'GOOD'

        
if __name__ == '__main__':
    # begin
    open_file = open("../test.in", 'rU')
    sys.stdout = open("../test.out", 'w')
    input_parameters = open_file.read().split('\n')
    num_case = int(input_parameters[0])
    pos = 1
    for index in range(num_case):
        n = int(input_parameters[pos])
        pos += 1
        expression = []
        for _ in range(n):
            expression.append(input_parameters[pos].strip())
            pos += 1
        print "Case #%d: %s" % (index + 1, Evaluation(expression, n))