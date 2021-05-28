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

def repeat(head):
    temp = head 
    if temp is None: 
        return
    while temp.next is not None: 
        if temp.data == temp.next.data: 
            new = temp.next.next
            temp.next = None
            temp.next = new 
        else: 
            temp = temp.next
            
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
le = repeat(l)
printll(le)