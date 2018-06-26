import math
def readInts():
    return list(map(int, raw_input().strip().split()))
def readInt():
    return int(raw_input())
def readIntsindex0():
    return list(map(lambda x: int(x) - 1, input().split()))
def readStrs():
    return raw_input().split()
def readStr():
    return raw_input()


for i in range(readInt()):
    d = {}
    n = readInt()
    for x in range(n):
        line = readStrs()
        if line[2] in d:
            d[line[2]].append(line[1])
        else:
            d[line[2]] = [line[1]]
        # print(d)

    res = 0
    v=d.values()
    # print v
    for y in v:
        if(len(y))>1:
            res += len(set(y))
    if res==0:
        print '-1'
    else:
        print res


'''
Input:
3
3
1400203032 nerdyninja 4e4d6c332b6fe62a63afe56171fd3725
1400233032 adikul30 7320eede6fd68c1d7a28506efbf593e7
1400201232 nerdyninja 4e4d6c332b6fe62a63afe56171fd3725
3
1400203032 nerdyninja 4e4d6c332b6fe62a63afe56171fd3725
1400233032 nerdyninja 7320eede6fd68c1d7a28506efbf593e7
1400201232 adikul30 4e4d6c332b6fe62a63afe56171fd3725
2
1400203032 nerdyninja 4e4d6c332b6fe62a63afe56171fd3725
1400201232 adikul30 7320eede6fd68c1d7a28506efbf593e7

Output:
1
2
-1

'''
