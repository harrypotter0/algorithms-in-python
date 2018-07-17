int_min = -float('inf')
def maxSubArraySum(a,k):
    max_so_far = int_min
    max_ending_here = 0
    while k:
        k-=1
        for i in range(0, len(a)):
            max_ending_here = max_ending_here + a[i]
            if (max_so_far < max_ending_here):
                max_so_far = max_ending_here

            if max_ending_here < 0:
                max_ending_here = 0

    return max_so_far

# Driver function to check the above function
#print "Maximum contiguous sum is", maxSubArraySum(a,len(a))

for __ in range(int(input())):
    n,k = map(int,raw_input().split())
    a = map(int,raw_input().split())
    s1 = maxSubArraySum(a , 1)
    s2 = maxSubArraySum(a , 2)
    s3 = maxSubArraySum(a , 3)
    s4 = maxSubArraySum(a , 4)

    if k == 1 :
        print s1
    elif k == 2:
        print s2
    else :
        print s2 + (k-2)*(s3-s2)
