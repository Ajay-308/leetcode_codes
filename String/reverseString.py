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


#using 2 pointers 

def reverseStr(str):
    n = len(str)
 
    i, j = 0, n-1
 
    # Swap character starting from
    # two corners
    # i is the left pointer and j is the right pointer
    while i < j:
        str[i], str[j] = str[j], str[i]
 
        i += 1
        j -= 1
 
