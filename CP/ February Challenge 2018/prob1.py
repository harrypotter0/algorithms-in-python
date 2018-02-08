import re

for _ in range(int(input())):
    c = 0
    s = raw_input()
    pattern = ['c','h','e','f']
    # s = ''.join([i for i in s if i.isalpha()])
    # s = s.lower()
    for i in range(len(s)-3) :
        if(s[i] in pattern and s[i+1] in pattern and s[i+2] in pattern and s[i+3] in pattern and s[i]!=s[i+1] and s[i]!=s[i+2] and s[i]!=s[i+3] and s[i+1]!=s[i+2]):
            if(s[i+1]!=s[i+3] and s[i+2]!=s[i+3]):
                c+=1
                # print(s[i]+s[i+1]+s[i+2]+s[i+3])
    if(c>0):
        print "lovely",c
    else :
        print "normal"
