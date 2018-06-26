# Utility function to read a list of numbers from stdin
def readInts():
    return map(int, [x.strip() for x in raw_input().strip().split(',')])

readInts()
a = readInts()

s = [0, 0, 0, 0, 0, 0]

# select max and place at 3, 2
# select max and place at 4, 1
# select max and place at 5, 0
s[3] = max(a)
a.remove(s[3])
s[2] = max(a)
a.remove(s[2])
s[4] = max(a)
a.remove(s[4])
s[1] = max(a)
a.remove(s[1])
s[5] = max(a)
a.remove(s[5])
s[0] = max(a)

# Reduce as Pascals Triangle until last before apex
while len(s) > 2:
    m = []
    for i in range(1, len(s)):
        m.append(s[i - 1] + s[i])
    s = m

# Print the product instead of sum for the last
print s[0] * s[1]
