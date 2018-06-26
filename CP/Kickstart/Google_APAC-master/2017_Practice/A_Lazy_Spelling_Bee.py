# !/usr/bin/env python
# coding=utf-8
import sys

def Lazy_Spelling_Bee(word):
    ls = len(word)
    if ls == 1:
        return 1
    res = 1
    for i in range(ls):
        # check the distinct characters in i - 1, i, i + 1
        choose = set([word[i]])
        if i - 1 >= 0:
            choose.add(word[i - 1])
        if i + 1 < ls:
            choose.add(word[i + 1])
        res *= len(choose)
    return res % 1000000007
        
if __name__ == '__main__':
    # begin
    open_file = open("../test.in", 'rU')
    sys.stdout = open("../test.out", 'w')
    input_parameters = open_file.read().split('\n')
    num_case = int(input_parameters[0])
    pos = 1
    for index in range(num_case):
        word = input_parameters[pos]
        pos += 1
        print "Case #%d: %d" % (index + 1, Lazy_Spelling_Bee(word))