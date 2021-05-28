def index(a):
    return a

def string_num(a):
    if len(a)==0:
        return 0
    b=a[1:]
    k=string_num(b)
    if ord(a[0])>=48 and ord(a[0])<=57:
        return k+(int(a[0])*(10**index(len(a)-1)))
a=input()
print(string_num(a))