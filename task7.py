array = input().split()
array = [int(x) for x in array]
if abs(array[4]-array[2])==abs(array[5]-array[3]):
    print("NO")
else:
    print("YES")

    
    
    