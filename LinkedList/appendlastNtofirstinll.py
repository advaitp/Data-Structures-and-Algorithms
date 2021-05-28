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
        
def append_LinkedList(head,n): 
    count=0
    curr=head
    prev=None
    le=lengths(head)
    
    while count<le-n:
        prev=curr
        curr=curr.next
        count+=1
    tail=None
    temp=curr
    while temp is not None:
        tail=temp
        temp=temp.next  
        
    prev.next=None
    tail.next=head
    
    return curr
        

            

    

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
from sys import setrecursionlimit
setrecursionlimit(11000)
arr=list(int(i) for i in input().split(' '))
# Create a Linked list after removing -1 from list
l = takeinput(arr)
i=int(input())
l = append_LinkedList(l, i)
printll(l)