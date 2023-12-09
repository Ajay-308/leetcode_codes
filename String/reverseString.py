//revers string using python

def reversebyStack(str):
     
    # using as stack
    stack = []
 
    for i in range(len(str)):
      # Push the charcters into stack
        stack.append(str[i])
     
    for i in range(len(str)):
       # Pop the charcters of stack into the original string.
        str[i] = stack.pop()
