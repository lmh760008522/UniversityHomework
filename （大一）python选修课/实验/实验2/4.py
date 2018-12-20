a,b=raw_input().split()
a,b=eval(a),eval(b)
if a<=0 :
    a=-a
if b <=0:
    b=-b
if a<b :
    a,b=b,a
x=a
y=b
d=x%y
while d!=0:
    x=y
    y=d
    d=x%y
    
m=y
n=a*b/y
print m,n
