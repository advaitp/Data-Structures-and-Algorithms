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

def swap_nodes(head, i, j):
    count=0
    count1=0
    curr=head
    prev=None
    curr1=head
    prev1=None
    if i==j:
        return
    
    while  count<i:
            prev=curr
            curr=curr.next
            count+=1
            
    while count1<j:
            prev1=curr1
            curr1=curr1.next   
            count1+=1
    if curr1 is not None and curr is not None: 
        if prev is not None :
            prev.next=curr1
        else:
            head=curr1
            
        if prev1 is not None :
            prev1.next=curr
        else:
            head=curr
            
        temp=curr.next
        curr.next=curr1.next
        curr1.next=temp
    return head 

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
i, j=list(int(i) for i in input().strip().split(' '))
l=swap_nodes(l, i, j)
printll(l)
