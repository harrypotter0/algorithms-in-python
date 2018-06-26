# !/usr/bin/env python
# coding=utf-8

import sys

def min_cover(n, l1, r1, a, b, c1, c2, m):
    res, total = 0, 0
    points = [(1, l1, 1), (1, r1 + 1, 0)]
    for i in range(1, n):
        x = (a * l1 + b * r1 + c1) % m
        y = (a * r1 + b * l1 + c2) % m
        points.append((i + 1, min(x, y), 1))
        points.append((i + 1, max(x, y) + 1, 0))
        l1, r1 = x, y
    points.sort(key=lambda x: x[1])
    unique_single = {}
    hasCovered = set()
    lastSingleId = lastStart = lastSingleStart = 0
    for point in points:
        if point[2] == 1:
            hasCovered.add(point[0])
        else:
            hasCovered.remove(point[0])
        if point[2] == 1 and len(hasCovered) == 1:
            # interval start
            lastStart = point[1]
        elif len(hasCovered) == 0:
            # interval end
            total += point[1] - lastStart
        if lastSingleId == 0 and len(hasCovered) == 1:
            # single start
            lastSingleStart = point[1]
            lastSingleId = list(hasCovered)[0]
        elif lastSingleId != 0 and len(hasCovered) != 1:
            # single end
            try:
                unique_single[lastSingleId] += point[1] - lastSingleStart
            except KeyError:
                unique_single[lastSingleId] = point[1] - lastSingleStart
            lastSingleId = 0
    maxSingle = max(unique_single.values())
    return total - maxSingle


if __name__ == '__main__':
    # begin
    open_file = open("../test.in", 'rU')
    sys.stdout = open("../test.out", 'w')
    input_parameters = open_file.read().split('\n')
    num_case = int(input_parameters[0])
    pos = 1
    for index in range(num_case):
        temp = input_parameters[pos].split(' ')
        (n, l1, r1, a, b, c1, c2, m) = [int(t) for t in temp]
        pos += 1
        print "Case #%d: %d" % (index + 1, min_cover(n, l1, r1, a, b, c1, c2, m))
