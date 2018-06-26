#!/usr/bin/env python

def process(N):
    if  not '4' in N:
        return '4' * (len(N) + 1)
    i = N.rindex('4')
    # print i
    return N[:i] + '7' + '4' * len(N[i+1:])

def main():
    T = int(raw_input().strip())
    for t in xrange(T):
        N = raw_input().strip()
        print process(N)

main()

'''
Input:
2
4
474315457575753234

Output:
7
74

'''
