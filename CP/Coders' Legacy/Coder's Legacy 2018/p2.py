
from math import floor
from fractions import Fraction as F
t = int(input())

for case in range(t):
    p, q, N = map(int, input().split())
    speed = abs(1 - F(p, q))
    time = F(1, 2) / speed * (N-1)
    print(floor(time+1))
