class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
class queue:
    def __init__(self):
        self.__head=None
        self.__tail=None
        self.__count=0
    def enqueue(self,data):
        node=Node(data)
        if self.__head is None:
            self.__head=node
        else:
            self.__tail.next=node
        self.__tail=node 
        self.__count=self.__count+1    
        
    def dequeue(self):
        if self.__head is None:
            return 
        data=self.__head.data
        self.__head=self.__head.next
        self.__count=self.__count-1
        return data
        
    def size(self):
        return   self.__count   
        
    def isempty(self):
        return  self.size() ==0
        
    def front(self):
        if self.__head is None:
            return 
        return self.__head.data


    
q = queue()
li = [int(ele) for ele in input().split()]
i=0
while i<len(li):
    choice = li[i]
    if choice == -1:
        break
    elif choice == 1:
        q.enqueue(li[i+1])
        i+=1
    elif choice == 2:
        ans = q.dequeue()
        if ans!=0:
            print(ans)
        else:
            print(-1)
    elif choice == 3:
        ans = q.front()
        if ans!=0:
            print(ans)
        else:
            print(-1)
    elif choice == 4:
        print(q.size())
    elif choice == 5:
        if(q.isempty()):
            print('true')
        else:
            print('false')
    i+=1






