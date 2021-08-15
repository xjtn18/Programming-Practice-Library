
"""
Notes


Insertion sort is good for cases where the list is already mostly sorted; bubble sort and selection sort should never be used.
"""





# Time: O(n^2)
# Space: O(1)
def bubblesort(nums : [int]) -> [int]:
    for i in range(len(nums)):
        for j in range(i, len(nums)):
            if nums[i] > nums[j]:
                nums[i], nums[j] = nums[j], nums[i] # swap

    return nums


# Time: O(n^2)
# Space: O(1)
def selectionsort(nums : [int]) -> [int]:
    for i in range(len(nums)):
        minidx = i
        for right in range(i+1, len(nums)):
            if nums[right] < nums[minidx]:
                minidx = right

        nums[minidx], nums[i] = nums[i], nums[minidx] # swap

    return nums


# Time: O(n^2)
# Space: O(1)
def insertionsort(nums : [int]) -> [int]:
    for i in range(1, len(nums)):
        currval = nums[i]
        j = i-1
        while j >= 0 and currval < nums[j]:
            nums[j+1] = nums[j]
            j -= 1
        nums[j+1] = currval
    return nums




t = [1,4,2,6,6,3,2,0]
print(bubblesort(t))

t = [-4,9,2,8,3,-4,2]
print(selectionsort(t))

t = [6,5,5,1,2,3,8,11,0]
print(insertionsort(t))


