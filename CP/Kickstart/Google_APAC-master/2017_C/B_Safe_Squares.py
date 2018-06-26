# !/usr/bin/env python
# coding=utf-8
import sys

def Safe_Squares(R, C, K, monsters):
    max_round = min(R, C)
    res = 0
    sqare = [[1] * C for _ in range(R)]
    for index in range(K):
        i, j = monsters[index]
        sqare[i][j] = 0
    update = R * C - K
    # use n - 1 square to generate n square
    for index in range(1, max_round + 1):
        if update == 0:
            break
        update = 0
        for i in range(R):
            for j in range(C):
                if sqare[i][j] == index:
                    res += 1
                    if i + 1 >= R or j + 1 >= C:
                        continue
                    if sqare[i + 1][j] == index and sqare[i][j + 1] == index \
                            and sqare[i + 1][j + 1] == index:
                        sqare[i][j] += 1
                        update += 1
    return res


if __name__ == '__main__':
    # begin
    open_file = open("../test.in", 'rU')
    sys.stdout = open("../test.out", 'w')
    input_parameters = open_file.read().split('\n')
    num_case = int(input_parameters[0])
    pos = 1
    for index in range(num_case):
        R, C, K = map(int, input_parameters[pos].split(' '))
        pos += 1
        monsters = []
        for i in range(K):
            monsters.append(map(int, input_parameters[pos].split(' ')))
            pos += 1
        print "Case #%d: %d" % (index + 1, Safe_Squares(R, C, K, monsters))