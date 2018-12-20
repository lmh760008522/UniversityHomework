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

def bi_search(a,low,height,n):
    mid=(low+height)/2
    if low>height:
        return -1
    else:
        if n<a[mid]:
            return bi_search(a,low,mid-1,n)
        elif n>a[mid]:
            return bi_search(a,mid+1,height,n)
        elif a[mid]==n:
            return a.index(n)
        


n=input()
a=prime(n)
length=len(a)
x1=input()
x2=input()
x3=input()
x4=input()
print bi_search(a,0,length-1,x1)
print bi_search(a,0,length-1,x2)
print bi_search(a,0,length-1,x3)
print bi_search(a,0,length-1,x4)
    
