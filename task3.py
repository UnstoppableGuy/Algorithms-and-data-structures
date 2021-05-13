def heapify(nums, heap_size, root_index):
    largest = root_index
    left_child = (2 * root_index) + 1
    right_child = (2 * root_index) + 2
    if left_child < heap_size and nums[left_child] > nums[largest]:
        largest = left_child
    if right_child < heap_size and nums[right_child] > nums[largest]:
        largest = right_child
    if largest != root_index:
        nums[root_index], nums[largest] = nums[largest], nums[root_index]
        heapify(nums, heap_size, largest)


def heap_sort(nums):
    n = len(nums)
    for i in range(n, -1, -1):
        heapify(nums, n, i)
    for i in range(n - 1, 0, -1):
        nums[i], nums[0] = nums[0], nums[i]
        heapify(nums, i, 0)


def get_list_max_values(count, nums):
    nums.sort(reverse=True, key=lambda x: abs(x))
    section = nums[:count]
    if count == len(nums):
        return nums
    size = len(list(filter(lambda x: x < 0, section)))
    if size % 2 == 0:
        return section
    if all([x <= 0 for x in nums]):
        return nums[len(nums)-count:len(nums)]
    min_list = [-1, -1]
    max_list = [-1, -1]
    for item in range(count-1, -1, -1):
        if section[item] < 0:
            min_list[1] = item
            break
    for item in range(count-1, -1, -1):
        if section[item] > 0:
            min_list[0] = item
            break
    section2 = nums[count::]
    for item in range(len(nums)-count):
        if section2[item] < 0:
            max_list[1] = item
            break
    for item in range(len(nums)-count):
        if section2[item] > 0:
            max_list[0] = item
            max_list[0] = item
            break
    if max_list[1] == -1:
        section[min_list[1]] = section2[max_list[0]]
        return section
    if max_list[0] == -1:
        section[min_list[0]] = section2[max_list[1]]
        return section
    if min_list[0] == -1:
        section[min_list[1]] = section2[max_list[0]]
        return section
    value1 = section[min_list[0]] * section2[max_list[0]]
    value2 = section[min_list[1]] * section2[max_list[1]]
    if value1 > value2:
        section[min_list[1]] = section2[max_list[0]]
    else:
        section[min_list[0]] = section2[max_list[1]]
    return section


def main():
    N, K = list(map(int, input().rstrip().split(' ')))
    A = list(map(int, input().rstrip().split(' ')))
    value = 1
    modul = 7 + 10**9
    for item in get_list_max_values(count=K, nums=A):
        value *= item
        value %= modul
    print(value)


if __name__ == '__main__':
    main()
