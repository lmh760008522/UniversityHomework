import sys
def printt(n):
    a=[]
    b=[]
    for i in range(n):
         a.append([])
         for j in range(n):
             a[i].append(0)

    for i in range(n):
        a[i][0]=1
        a[i][i]=1

    for i in range(2,n):
        for j in range(1,i):
            a[i][j]=a[i-1][j-1]+a[i-1][j]

    for i in range(n):
        for k in xrange(0,n-i-1):
            sys.stdout.write(' ')
        for j in range(i+1):
            print a[i][j],
        print
       
n=input()
if n<0:
    n=-n
printt(n)
