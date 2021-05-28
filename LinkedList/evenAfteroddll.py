# Problem ID 331 even after odd in a LL
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

def printll(head):
    while head is not None:
        print(head.data,end=" ")
        head = head.next

def takeinput(ins):
    #ins=[int(x) for x in input().split()]
    head=None
    tail=None
    for a in ins :
        if a==-1:
            break
        new_node=Node(a)
        if head is None:               #to initialise  the value of head and it keep it same
            head=new_node
            tail=new_node
        else:
            tail.next=new_node
            tail=new_node       
    return head

def arrange_LinkedList(head):
    evenh=None
    oddh=None
    event=None
    oddt=None
    curr=head
    curr1=head
    tail=None
    while curr is not None:
        if curr.data %2==0:
            evenh=Node(curr.data)
            event=Node(curr.data)
            curr=curr.next
            break
        curr=curr.next 
        
    while curr1 is not None:    
        if curr1.data%2!=0:
            oddh=Node(curr1.data)
            oddt=Node(curr1.data)
            curr1=curr1.next
            break
        curr1=curr1.next
    temp=event
    temp1=oddt
   
    while curr is not None:
        if curr.data %2==0:
            temp.next=Node(curr.data)
            temp=temp.next
        curr=curr.next 
        
    while curr1 is not None:        
        if curr1.data %2 !=0:
            temp1.next=Node(curr1.data)
            temp1=temp1.next
        curr1=curr1.next
           
    if temp1 is not None:
        temp1.next=event 
    else:
        return event
    return oddt
    
    
    
arr=list(int(i) for i in input().strip().split(' '))
# Create a Linked list after removing -1 from list
l = takeinput(arr)
l = arrange_LinkedList(l)
printll(l)
    