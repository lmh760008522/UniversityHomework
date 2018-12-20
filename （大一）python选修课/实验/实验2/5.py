import math
def prime(n):
    if n==1 :
        return False 
    elif n==2:
        return True
    else:
        for i in range(2,n-1):
            if n%i==0 :
                return False
        return True

m,n=raw_input().split()
m,n=eval(m),eval(n)
s=0
count=0
if m==n:
    if prime(m):
        s=m
        count=1
    
else:
    for i in range (m,n+1):
       if prime(i):
           print i
           count=count+1
           s=s+i
print count,s
