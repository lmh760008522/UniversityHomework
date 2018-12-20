n=input()
if n<0 :
    n=-n
a=1;
for i in range (1,n+1):
    a*=i
print"%d! = %d"%(n,a)
