import sys

sys.setrecursionlimit(30000)


# O(n)
def merge(arr1: list, arr2: list) -> list:
    # 断言 arr 为已经排好序的数组
    arr = []
    while arr1 and arr2:
        if arr1[0] >= arr2[0]:
            arr.append(arr2.pop(0))
        else:
            arr.append(arr1.pop(0))
    if arr1:
        arr.extend(arr1)
    if arr2:
        arr.extend(arr2)
    return arr

# O(lgn)
def sort(arr: list) -> list:    # 断言
    if len(arr) <= 1:
        return arr
    mid = len(arr)//2
    l = arr[:mid]
    r = arr[mid:]
    l = sort(l)
    r = sort(r)
    arr = merge(l, r)
    return arr


if __name__ == "__main__":
    arr = [1, 5, 2]
    print(sort(arr))
