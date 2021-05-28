## Read input as specified in the question.
## Print output as specified in the question.

class complex:
    def __init__(self,r,c):
        self.real=r
        self.complex=c
    def prints(self):
        if self.real ==0 and self.complex==0:
            print(0)
        else:
            print(self.real,'+ i'+str(self.complex))   
    def plus(self,num):
        Real=self.real+num.real
        Complex=self.complex+num.complex   
        self.real=Real
        self.complex=Complex
    def multiply(self,num):
        Real=(self.real*num.real)-(self.complex*num.complex)
        Complex=(self.real*num.complex)+(self.complex*num.real)
        
        self.real=Real
        self.complex=Complex
        
r1,i1=[int(x) for x in input().split()]
r2,i2=[int(x) for x in input().split()]
i=int(input())
n1=complex(r1,i1)
n2=complex(r2,i2)
if i==1:
    n1.plus(n2)
    n1.prints()
elif i==2:
    n1.multiply(n2)
    n1.prints()
        