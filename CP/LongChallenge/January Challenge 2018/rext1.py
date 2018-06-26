for x in xrange(int(raw_input())):
  l = map(int, raw_input().split())
  l = sorted(l)
  if l[0] == l[1] and l[2] == l[3]:
    print 'YES'
  else:
    print 'NO'     
