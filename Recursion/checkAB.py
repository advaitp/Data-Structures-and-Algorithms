## Read input as specified in the question.
## Print output as specified in the question.
def check_ab(str):
    l=len(str)
    if l==0:
        return True
    if str[0]=='a':
        if len(str[1:])>0:
            if str[1]=='a' or str[1]=='':
                return check_ab(str[1:])
            elif str[1]=='b' and str[2]=='b':
                return check_ab(str[3:])
            else:
                return False
        else:
            return True
    else: 
        return False

str=input()  
check_string=check_ab(str)
if check_string:
    print('true')
else:
    print('false')