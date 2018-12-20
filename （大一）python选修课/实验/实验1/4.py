from string import upper
lenth=raw_input()
lenth=lenth.upper()
if lenth[-4:]=='INCH':
    l=eval(lenth[0:-4])*0.0254
    print"The lenth is %fm"%l
elif lenth[-4:]=='MILE':
    l=eval(lenth[0:-4])*1.6093
    print"The lenth is %fkm"%l
elif lenth[-2:]=='KM':
    l=eval(lenth[0:-2])/1.6093
    print"The lenth is %fmile"%l
elif lenth[-1:]=='M':
    l=eval(lenth[0:-1])/0.0254
    print"The lenth is %finch"%l
else:
    print"Error"
