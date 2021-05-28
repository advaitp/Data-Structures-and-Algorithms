def pair_star(a):
    if len(a)==1:
        return a
    b=a[1:]
    k=pair_star(b)
    if a[0]==a[1]:
        return a[0]+'*'+k
    else:
        return a[0]+k
a=input()
print(pair_star(a))