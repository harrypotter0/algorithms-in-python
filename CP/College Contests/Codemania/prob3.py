import math
t = int(input())
for tc in range(t):
    a = input()
    b = input()
    inta = 0
    intb = 0
    cnta = 0
    cntb = 0
    # 1st team
    vala = a.find('!')
    if vala > 0:
        inta = int(a[:vala])
        cnta = len(a) - vala
    else:
        inta = int(a)
    valb = b.find('!')
    # print(valb)
    # 2nd team
    if valb > 0:
        intb = int(b[:valb])
        cntb = len(b) - valb
    else:
        intb = int(b)
    # print("cnta",cnta ,"cntb",cntb)
    # fact(13) > 10^9 so calculate upto 12
    while cnta > 0 and inta < 13:
        # print("aaaaaa")
        cnta -= 1
        inta = math.factorial(inta)
    while cntb > 0 and intb < 13:
        # print("bbbbbb")
        cntb -= 1
        intb = math.factorial(intb)
    # print("cnta",cnta ,"cntb",cntb)
    if cnta == cntb:
        if inta > intb:
            print(1)
        elif inta < intb:
            print(-1)
        else:
            print(0)
    elif cnta < cntb:
        print(-1)
    elif cnta > cntb:
        print(1)
