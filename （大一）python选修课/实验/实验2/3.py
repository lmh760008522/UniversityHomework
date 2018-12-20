N=input()
if (N==1):
    count=1
elif N==2:
    count=2
else:
    a=1
    b=1
    c=a+b
    count=3
    while (c<N):
       a=b
       b=c
       c=a+b
       count+=1
print count
