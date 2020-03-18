def find(arr: list, start: int, end: int, key: int) -> int:
    if start > end:
        return -1
    mid = int(start+(end-start)/2)
    if arr[mid] == key:
        return mid
    if arr[mid] > key:
        return find(arr, 0, mid, key)
    if arr[mid] < key:
        return find(arr, mid, end, key)
    return -1


# 搜索第一个比他小|大的
def find1(arr: list, start: int, end: int, key: int) -> int:
    if start > end:
        return -1
    if len(arr) < 2:
        return -1
    mid = int(start+(end-start)/2)
    if key >= arr[mid] and key <= arr[mid+1]:
        return mid
    if key < arr[mid]:
        return find1(arr, 0, mid, key)
    if key > arr[mid]:
        return find1(arr, mid, end, key)
    return -1


if __name__ == "__main__":
    arr = [0, 1, 2, 3, 4, 5, 6, 7, 8, 10, 12, 15, 45, 78]
    index = find1(arr, 0, len(arr)-1, 5)
    print(arr[index], index)
