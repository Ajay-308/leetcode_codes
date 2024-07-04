import time
import random
import matplotlib.pyplot as plt
def selection_sort(arr):
n = len(arr)
for i in range(n):
minIndex = i
for j in range(i+1, n):
if arr[j] < arr[minIndex]:
minIndex = j
(arr[i], arr[minIndex]) = (arr[minIndex], arr[i])
def bubble_sort(arr):
n = len(arr)
for i in range(n):
for j in range(n-i-1):
if arr[j] > arr[j+1]:
(arr[j], arr[j+1]) = (arr[j+1], arr[j])
def merge_sort(arr):
if len(arr) <= 1:
return arr
mid = len(arr) // 2
left_arr = merge_sort(arr[:mid])
right_arr = merge_sort(arr[mid:])
return merge(left_arr, right_arr)
def merge(left_arr, right_arr):
result = []
i, j = 0, 0
while i < len(left_arr) and j < len(right_arr):
if left_arr[i] < right_arr[j]:
result.append(left_arr[i])
i += 1
else:
result.append(right_arr[j])
j += 1
result += left_arr[i:]
result += right_arr[j:]
return result
def quick_sort(arr, s, e):
if s < e:
partition_index = partition(arr, s, e)
quick_sort(arr, s, partition_index - 1)
quick_sort(arr, partition_index + 1, e)
def partition(arr, s, e):
pivot = arr[e]
i = s - 1
for j in range(s, e):
if arr[j] <= pivot:
i += 1
arr[i], arr[j] = arr[j], arr[i]
arr[i+1], arr[e] = arr[e], arr[i+1]
return i+1
# Plotting the complexity chart
selection_sort_times = []
bubble_sort_times = []
merge_sort_times = []
quick_sort_times = []
data_array = []
for i in range(10, 101):
data_array.append(i)
l= []
for j in range(0, i):
l.append(random.randint(100, 1000))
start_time = time.time()
selection_sort(l)
selection_sort_times.append(time.time() - start_time)
start_time = time.time()
bubble_sort(l)
bubble_sort_times.append(time.time() - start_time)
start_time = time.time()
merge_sort(l)
merge_sort_times.append(time.time() - start_time)
start_time = time.time()
quick_sort(l, 0, len(l) - 1)
quick_sort_times.append(time.time() - start_time)
plt.plot(data_array, selection_sort_times, label='Selection Sort')
plt.plot(data_array, merge_sort_times, label='Merge Sort')
plt.plot(data_array, quick_sort_times, label='Quick Sort')
plt.plot(data_array, bubble_sort_times, label='Bubble Sort')
plt.xlabel('Size of Array (n)')
plt.ylabel('Time (seconds)')
plt.title('Time Complexity Chart for Sorting Algorithms')
plt.legend()
plt.show()
