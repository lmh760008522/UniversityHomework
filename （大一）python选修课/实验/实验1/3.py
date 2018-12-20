from random import*
n=input()
seed(n)
for i in range(1,11):
    x=randint(100,999)
    a=x/100
    b=x/10%10
    c=x%10
    if x==a**3+b**3+c**3:
        print"%d=%d**3+%d**3+%d**3"%(x,a,b,c)
        break
    else:
        print"%d is not a narcissistic number"%x
