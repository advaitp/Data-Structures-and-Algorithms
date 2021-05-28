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

def bubbleSortLL(head) :
    len=lengths(head)
    if head is None:
        return
    for i in range(len-1):
        prev=None
        curr=head
        while curr:
            nex=curr.next
            if curr.next is not None: 
                if curr is not None and curr.data<=curr.next.data and curr.next is not None : 
                    prev=curr
                    curr=curr.next
                elif curr is not None and curr.data>curr.next.data and prev is not None  :
                    prev.next=curr.next
                    curr.next=nex.next
                    nex.next=curr
                    prev=prev.next
                elif curr is not None and curr.data>=curr.next.data and prev is None  :
                    curr.next=nex.next
                    nex.next=curr
                    prev=nex
                    head=prev
            else:
                curr=curr.next
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

def printll(head):
    while head:
        print(head.data, end=' ')
        head = head.next
    print()

# Main
# Read the link list elements including -1
arr=list(int(i) for i in input().strip().split(' '))
# Create a Linked list after removing -1 from list
l = takeinput(arr)
l = bubbleSortLL(l)
printll(l)

