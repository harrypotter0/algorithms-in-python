for i in xrange(input()):
    n = input()
    l = []
    for i in xrange(n):
        l.append(raw_input())
    #print(l)
    l2 = list(set(l))
    #print(l2)
    if len(l2) == 0:
        print "Draw"
        continue
    if len(l2) == 1:
        print l2[0]
        continue
    c1 = l.count(l2[0])
    c2 = l.count(l2[1])
    if c1!=c2:
        if c1 > c2:
            print l2[0]
        else:
            print l2[1]
    else:
        print "Draw"
