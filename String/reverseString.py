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


#using  recurrsion

# Recursive Python program to reverse a string
 
def recursiveReverse(str, i = 0):
    n = len(str)
 
    if i == n // 2:
        return
    # Swap the i and n-i-1 character
    str[i], str[n-i-1] = str[n-i-1], str[i]
     
    # Call Recursive function after incrementing i.
    recursiveReverse(str, i+1)
 
        i += 1
        j -= 1
 
