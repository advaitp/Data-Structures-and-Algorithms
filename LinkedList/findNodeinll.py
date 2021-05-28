class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def linearSearch(head, n):
    #  Given a linked list and an integer n you need to find and return index
    #  where n is present in the LL. Do this iteratively. Return -1 if n is not
    #  present in the LL. Indexing of nodes starts from 0. 
    #############################
    # PLEASE ADD YOUR CODE HERE #
    #############################
    count=0
    while head is not None:
        if head.data==n:
            return count
        count+=1
        head=head.next
    return -1    
            

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
data=int(input())
index = linearSearch(l, data)
print(index)