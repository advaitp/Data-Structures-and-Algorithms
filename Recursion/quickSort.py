def partition(st,s,e):
    count=0
    p=st[s]  
    i=s
    j=e #pivot point is start initailly
    for g in range(s,e+1):
        if st[g]<p:
            count+=1
    #change position of pivot element to desired position
    st[s],st[s+count]=st[s+count],st[s]
    pivot=s+count # pivot index
   
    while i<=j:
         if st[i]<p:
            i+=1
         elif st[j]>=p:    
            j-=1   
         else :
            st[i],st[j]=st[j],st[i]
            i+=1
            j-=1
       
    return pivot    

def quicksort(st,s,e):
    if s>=e:
        return
    pi=partition(st,s,e)
    quicksort(st,s,pi-1)
    quicksort(st,pi+1,e)
    
n=int(input())
a=[int(x) for x in input().split()]    
quicksort(a,0,len(a)-1)
for j in a:
    print(j,end=" ")
