for z in range(int(input())):
  s=0
  n = int(input())
  bi=bin(n)[2:]
  length=len(bi)
  for i in range(length):
    for j in range(1,length):
      if i<j :
          s+=int(bi[i])*2+int(bi[j])
  print(s)
