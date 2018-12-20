n=int(input())
for i in range(0,n+1):
    for j in range (1,n-i+1):
        print'',
    print"*"*(2*i-1)
for i in range(1,n):
    for j in range(1,i+1):
        print'',
    print"*"*(2*n-2*i-1)
