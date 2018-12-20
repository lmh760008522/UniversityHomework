def prime(n):
    p=[];
    for i in range(2,n+1):
        flag=1
        for j in range(2,i):
            if(i%j==0):
                flag=0
                break
        if(flag==1):
            p.append(i)
    return p

def bi_search(x,p,l,r):
    mid=(l+r)/2
    if l>=r:
        if x==p[mid-1]:
            return mid-1
        else:
            return -1
    if x>=p[mid]:
        ans=bi_search(x,p,mid+1,r)
    else:
        ans=bi_search(x,p,l,mid)
    return ans

n=input()
p=prime(n)
r=len(p)
while(1):
    x=input()
    ans=bi_search(x,p,0,r)
    print ans
