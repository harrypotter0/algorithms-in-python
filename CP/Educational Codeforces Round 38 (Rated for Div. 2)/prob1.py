n=input()
s=raw_input()
vowels="aeiouy"
ans=""
i=0
while i<n:
    ans+=str(s[i])
    if s[i] not in vowels:
        i+=1
        continue
    while i<n and s[i] in vowels:i+=1
print ans
