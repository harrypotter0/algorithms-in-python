import string
n, m = map(int, input().split())
s = input()
s1 = string.ascii_lowercase
for i in range(m):
	x, y = input().split()
	s1 = s1.translate(str.maketrans(x+y, y+x))
print(s.translate(str.maketrans(string.ascii_lowercase, s1)))