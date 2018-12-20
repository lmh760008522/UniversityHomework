x=raw_input()
x=eval(x)
a=raw_input().split( )
if x<0:
    x=-x
s=0.0
count=0
for i in range(0,x) :
    a[i]=eval(a[i])
    s+=a[i]
    if a[i]>=60:
        count=count+1
average=s/x
tem='%f'%average
print "average =",average
print"count = %d"%count
