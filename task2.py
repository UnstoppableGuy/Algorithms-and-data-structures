count = int(input())
numbers = input().split()
array = [(int(numbers[item]))for item in range(count)]
array.sort()

if array[-1]*array[-2] < array[0]*array[1]:
    print(array[0]*array[1])
else:
    print(array[-1]*array[-2])
        
   
