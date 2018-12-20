def judgeprime(n):
    if n==1:
        return 0
    else:
        for i in range(2,n-1):
            if n%i==0:
                return 0
        return 1
    
def prime(n):
    num=0
    a=[2]
    if n==1:
        return 0;
    elif n==2:
        return a
    else:
        for i in range(3,n):
            if judgeprime(i):
                a.append(i)
        sorted(a)
        return a

def bi_search(n,a,length):
    mid=(length-1)/2
    if n==a[mid]:
        return a.index(n)
    elif n!=a[mid]&mid==0:
        return -1
    elif n<a[mid]:
        return bi_search(n,a,length-mid)
    elif n>a[mid]:
        return bi_search(n,a,length+mid)

n=input()
a=prime(n)
print a
length=len(a)
x=input()
y=bi_search(x,a,length)
print y
 
            



        

