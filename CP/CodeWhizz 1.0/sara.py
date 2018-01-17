for _ in range(int(input())):
    n = int(input())
    steps = 0
    while(n!=1):
        if(n%3==0):
            n /=3
            steps +=1
            #print(steps,n)
        elif((n-1)%3==0):
            n-=1
            steps+=1
            #print(steps,n)
        elif((n+1)%3==0):
            n+=1
            steps+=1
            #print(steps,n)
    print(steps)
