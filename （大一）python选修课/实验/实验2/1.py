x,y,z=raw_input().split('/')
x,y,z=eval(x),eval(y),eval(z)
s=0
if((x%400==0)or(x%4==0 and x%100!=0)):
    for i in range(0,y):
        if (i==1 or i==3 or i==5 or i==7 or i==8 or i==10 or i==12):
            s=s+31
        elif i==2:
            s=s+29
        elif i==0:
            s=s+0
        else :
            s=s+30
else:
     for i in range(0,y):
        if( i==1 or i==3 or i==5 or i==7 or i==8 or i==10 or i==12):
            s=s+31
        elif i==2:
            s=s+28
        elif i==0:
            s=s+0
        else :
            s=s+30
s=s+z
print s
    
            
