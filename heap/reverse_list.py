def reverse(arr, start):
    l, r = start, len(arr)-1
    while l < r:
        arr[l], arr[r] = arr[r], arr[l]
        l+=1
        r-=1
    print(arr)

lis = [1,2,3,4,5,6]
reverse(lis, 2)
