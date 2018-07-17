'''

1
5 5
0 0 0 -1 5
0 0 0 -1 0
1 0 0 0 0
0 0 0 0 0
0 0 0 0 0

'''

for _ in range(int(raw_input())):
    n,m = map(int,raw_input().split())
    ar = []
    mx = 0
    for i in range(n):
        ar.append(map(int,raw_input().split()))
        # print(ar)
        # print(max(ar[-1]))
        mx = max(max(ar[-1]),mx )
        # print(mx)

    vis=[]
    for i in range(n):
        vis.append([0]*m)
    # print(vis)

    v=[]
    for i in range(mx+1):
        v.append([])
    # print(v)

    for i in range(n):
        for j in range(m):
            if ar[i][j] > 0:
                v[ar[i][j]].append((i,j))
    # print v

    for i in range(mx,0,-1):
        for cx,cy in v[i]:
            # print cx,cy
            if vis[cx][cy] == 2:
                continue
            if cx+1 < n and ar[cx+1][cy]!=-1 and vis[cx+1][cy]==0:
                vis[cx+1][cy] = 1
                v[i-1].append((cx+1,cy))
            if cx-1 > -1 and ar[cx-1][cy]!=-1 and vis[cx-1][cy]==0:
                vis[cx-1][cy] = 1
                v[i-1].append((cx-1,cy))
            if cy+1 < m and ar[cx][cy+1]!=-1 and vis[cx][cy+1]==0:
                vis[cx][cy+1] = 1
                v[i-1].append((cx,cy+1))
            if cy-1 > -1 and ar[cx][cy-1]!=-1 and vis[cx][cy-1]==0:
                vis[cx][cy-1] = 1
                v[i-1].append((cx,cy-1))
            vis[cx][cy] = 2
            # print vis
            # for __ in vis:
                # print(__)
            # print "fuck me mother-fucker"
        # print v
    # print v

    for i in range(n):
        st = ''
        for j in range(m):
            if ar[i][j] ==-1:
                st += 'B'
            elif vis[i][j]>0:
                st+='Y'
            else:
                st+='N'
        print st
