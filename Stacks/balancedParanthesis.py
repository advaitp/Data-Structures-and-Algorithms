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
        
def checkBalanced(expr):
    s=stack()
    bracket={'{':'}','[':']','(':')',')':'(',']':'[','}':'{'}
    for a in expr:
        if a in bracket.keys() :
            if s.isempty() is True:
                s.push(a)
            else:    
                if a==bracket[s.top()]:
                    s.pop()
                else:
                    s.push(a)
                    
    return s.isempty()
expr=input()
if checkBalanced(expr):
    print('true')
else:
    print('false')

