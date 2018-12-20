n=input()
a=[([0]*n) for i in range(n)]
print a
for i in range(0,n):
    a[i][0]=1
    a[i][i]=1
    
for i in range(2,n):
    for j in range(1,i):
        a[i][j]=a[i-1][j-1]+a[i-1][j]
        
for i in range(0,n):
    if i!=(n-1):
        print " "*(n-i-2),
    for j in range (0,i+1):
        print a[i][j],
    print

