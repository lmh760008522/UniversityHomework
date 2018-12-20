n=input()
for i in range (1,n+1):
    s=""
    for j in range (1,n-i+1):
        s=s+' '
    for j in range (1,2*i):
        s=s+'*'
    print s
for i in range(n+1,2*n):
    s=""
    for j in range(2,n-(2*n-i)+2):
        s=s+' '
    for j in range(1,2*(2*n-i)):
        s=s+'*'
    print s
