ans = ['NO','YES']
for kohli in range(input()):
    fi,se,th,fo = map(int,raw_input().split())
    print ans[((fi^se^th^fo)==0)]
