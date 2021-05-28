class queue:
    def __init__(self):
        self.__arr=[]
        self.__count=0
        self.__front=0
        
    def enqueue(self,data):
        self.__arr.append(data)
        self.__count+=1
        
    def dequeue(self):
        if self.__count<=0:
            return -1
        ele=self.__arr[self.__front]
        self.__count-=1
        self.__front+=1
        return ele
    
    def size(self):
        return self.__count
        
    def isempty(self):
        return self.size() ==0
            
    def front(self): 
        if self.__count==0:
            return -1
        return self.__arr[self.__front]



def reverse(q1):
    if q1.size()==1:
        return q1.front()
    fron=q1.front()
    q1.dequeue()
    reverse(q1)
    q1.enqueue(fron)    

#Implement Your Code Here     

        
from sys import setrecursionlimit
setrecursionlimit(11000)
n = int(input())
li = [int(ele) for ele in input().split()]
k = int(input()) 
q = queue()
q1=queue()
for ele in li:
	q.enqueue(ele)
for i in range(k):
    q1.enqueue(q.front())
    q.dequeue()
reverse(q1)

while q.size()>0:
    q1.enqueue(q.front())
    q.dequeue()
    

while(q1.size()>0):
	print(q1.dequeue())