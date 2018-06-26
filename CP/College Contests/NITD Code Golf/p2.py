from collections import Counter
def readInt():
    return int(raw_input())
def readStr():
    return raw_input()

arr =[]
t =readInt()
for __ in range(t):
    s = readStr()
    arr.append(s)
maxi =0
thelist = Counter(arr)
for k in arr:
    if(thelist[k]>=maxi):
        maxi = thelist[k]
        ans = k
print ans
