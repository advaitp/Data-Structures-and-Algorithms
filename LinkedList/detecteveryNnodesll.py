class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        
def lengths(head):
    if head is None:
        return 0
    else:
        count=lengths(head.next)   
    return count+1    
def skipMdeleteN(head, M, N):
    curr=head
    count1=1
    count2=1
    temp1=curr
    temp2=curr
    while temp2: 
        if M>0 and N>0:
            while count1<M :
                if temp1 is not None:
                    temp1=temp1.next
                    count1+=1
                else:
                    return head
            temp2=temp1.next    
            while count2<N :
                if temp2 is not None:
                    temp2=temp2.next
                    count2+=1
                else:
                    break
          
            if temp2 is not None and count2==N:    
                temp2=temp2.next  
                temp1.next=temp2
                temp1=temp2
            else:
                temp1.next=None
            count1=1
            count2=1
        elif M<=0 and N<=0:
            return
    return curr   
            
def ll(arr):
    if len(arr)==0:
        return None
    head = Node(arr[0])
    last = head
    for data in arr[1:]:
        last.next = Node(data)
        last = last.next
    return head

def printll(head):
    while head:
        print(head.data, end=' ')
        head = head.next
    print()

# Main
# Read the link list elements including -1
arr=list(int(i) for i in input().strip().split(' '))
# Create a Linked list after removing -1 from list
l = ll(arr[:-1])
m=int(input())
n=int(input())
l = skipMdeleteN(l, m, n)
printll(l) 
