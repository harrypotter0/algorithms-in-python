for _ in range(input()):
    arr=list(raw_input())
    string=''
    for i in arr:
        if ord('A')<=ord(i)<=ord('D'):
            string+='A'
        elif ord('E')<=ord(i)<=ord('H'):
            string+='H'
        elif ord('I')<=ord(i)<=ord('K'):
            string+='I'
        elif ord('L')<=ord(i)<=ord('N'):
            string+="M"
        elif ord("O")<=ord(i)<=ord("Q"):
            string+="O"
        elif ord("R")<=ord(i)<=ord("T"):
            string+="T"
        elif i=="U" or i=="V" or i=="W" or i=="X" or i=="Y":
            string+=i
        elif i=="Z":
            string+="A"
    print string
