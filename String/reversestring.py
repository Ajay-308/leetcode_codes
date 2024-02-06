from collections import deque

def left_rotate_string(s, d):
	char_deque = deque(s)
	char_deque.rotate(-d)
	return ''.join(char_deque)

def right_rotate_string(s, d):
	char_deque = deque(s)
	char_deque.rotate(d)
	return ''.join(char_deque)

s = "GeeksforGeeks"
d = 2
print("Left Rotation:", left_rotate_string(s, d))
print("Right Rotation:", right_rotate_string(s, d))

s = "qwertyu"
d = 2
print("Left Rotation:", left_rotate_string(s, d))
print("Right Rotation:", right_rotate_string(s, d))


//output

Left Rotation: eksforGeeksGe
Right Rotation: ksGeeksforGee
Left Rotation: ertyuqw
Right Rotation: yuqwert
