s=raw_input()
A=s.split()
while(1):
    s=raw_input()
    ans=[]
    end=len(s)
    while(end!=0):
        i=0;
        tmp=s[i:end]
        while((tmp in A)==False):
            i=i+1
            tmp=s[i:end]
        ans.append(tmp)
        end=i
    ans.reverse()
    for i in ans:
        print i,
    print


