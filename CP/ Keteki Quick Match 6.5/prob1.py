for __ in range(int(input())):
    k = int(raw_input())
    p = list()
    ne= list()
    n1 = list()
    for j in range(k):
        n1 = raw_input().split()
        s1 = raw_input()
        if s1=="yes":
            p.extend(n1)
        else:
            ne.extend(n1)
    # print(p)
    # print(ne)
    #
    # print(set(p))
    # print(set(ne))
    # print(set(p)-set(ne))

    print(len(set(p)-set(ne)))
    # print(p)
    # print(ne)
