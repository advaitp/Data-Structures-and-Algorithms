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

def reverse(head):
    curr=head
    prev=None
    while curr is not None:
        next=curr.next
        curr.next=prev
        prev=curr
        curr=next
    head=prev   
    
    return head  

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


# Main
# Read the link list elements including -1
arr=list(int(i) for i in input().split(' '))
# Create a Linked list after removing -1 from list
l = takeinput(arr)
le = reverse(l)
printll(le)