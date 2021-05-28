def merge(sm1,sm2,st):
    arr1=sm1
    arr2=sm2
    i=0
    j=0
    k=0
    while i<len(arr1) and j<len(arr2):
        if arr1[i]<=arr2[j]:
            st[k]=arr1[i]
            i+=1
            k+=1
        elif arr2[j]<=arr1[i]:
            st[k]=arr2[j]
            j+=1
            k+=1
    while i<len(arr1):
        st[k]=arr1[i]
        k+=1
        i+=1
    while j<len(arr2):
        st[k]=arr2[j]
        k+=1
        j+=1 
        
def mergesortr(st):
    if len(st)==0 or len(st)==1 :
        return 
    m=len(st)//2
    a1=st[0:m]
    a2=st[m:]
    mergesortr(a1)
    mergesortr(a2)
    merge(a1,a2,st) 

n=int(input())
st=[int(x) for x in input().split()]
mergesortr(st)
for j in st:
    print(j,end=" ")