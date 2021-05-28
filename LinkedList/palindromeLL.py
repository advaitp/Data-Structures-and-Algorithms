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

def palindrome(head):
    le=lengths(head)
    curr=head
    if le%2==0:
        mid=le//2      
    elif le%2!=0:
        mid=(le+1)//2
    for i in range(1, mid):  
        curr=curr.next
    rhead=reverse(curr.next)  
    while head != None and rhead != None:
        if head.data!=rhead.data:
            bool=False
            break
        else:
            head=head.next
            rhead=rhead.next
            
            bool=True
    return bool    
        
            
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
le = palindrome(l)
if(le):  
    print("true");  
else:  
    print("false");    
