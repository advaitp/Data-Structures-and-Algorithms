class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        
class stack:
    def __init__(self):
        self.__data=[]
    def isempty(self):
        return self.size()==0    
    def push(self,item):
        return self.__data.append(item)
    def pop(self):
        if self.isempty():
            return
        else:
            return self.__data.pop()
    def top(self):
        if self.isempty():
            return
        else:
            return self.__data[self.size()-1]
    def size(self):
        return len(self.__data)    
        
def stockSpan(price,n):
    s=stack()
    l=len(price)
    count=1
    for j in price:
        s.push(j)
    s.pop()
    if s.isempty() is False:
        i=price[l-1]
        for j in range(l-1):
            if s.top()<i:
                count+=1
                s.pop()
            else:
                break
    else:
        count=1
    return count        
#### Implement Your Code Here
n = int(input())
price = [int(ele) for ele in input().split()]
for i in range(n):
    print(stockSpan(price[:i+1],n),end=" ")






