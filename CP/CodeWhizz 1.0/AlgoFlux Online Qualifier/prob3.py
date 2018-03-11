for kohli in range(input()):
    a = raw_input()
    b = raw_input()
    n = len(a)
    m = len(b)
    t = m//n
    # print "aage baddd "
    # print a,b,n,m
    # print "aage baddd ",t
    for i in range(t):
        if(b.find(a)!=-1):
            b = b.replace(a,'')
            # print b
        # print b
    if(b==''):
        print "YES"
    else:
        print "NO"

'''

4
ab
abab
ab
aabb
ab
aba
abc
aabcbcabc

'''
