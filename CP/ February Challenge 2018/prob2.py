import re
for _ in range(int(input())):
    n,m,x,k= map(int,raw_input().split())
    string = raw_input()
    oddp,evenp = 0,0
    for i in range(int(len(string))):
        if(string[i]=='O'):
            oddp+=1
        else:
            evenp+=1
    if(m*x<n or n>k):
        print("no")
        continue
    # if(m==1 and not(re.search('O',string))):
    #     print("no")
    #     continue
    # # print(re.search('O',string))
    evenpm = m/2
    oddpm = m%2 + m/2
    evenp = (evenp/x)*x
    oddp = (oddp/x)*x
    e = min(evenp,evenpm*x)
    o = min(oddp,oddpm*x)
    # print(evenp,evenpm,oddp,oddpm,e,o)
    summ = e+o
    if(summ>=n):
        print("yes")
    else :
        print("no")
