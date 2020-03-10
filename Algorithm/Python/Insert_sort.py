import sys

sys.setrecursionlimit(30000)

# O(n^2)
def sort(arr: list, reverse: bool = False) -> list:  # 断言：比key大的排右边
    if len(arr) <= 1:
        return arr
    if reverse:
        def comp(x, y): return x < y
    else:
        def comp(x, y): return x > y                # 1.初始化成立
    for index in range(1, len(arr)):
        key = arr[index]                            # 2.1 进入循环时成立
        _index = index-1
        while _index >= 0 and comp(arr[_index], key):
            arr[_index+1] = arr[_index]
            _index -= 1
        arr[_index+1] = key                         # 2.2 循环退出时成立
    return arr                                      # 3.不变式成立


# 递归版本 O(nlogn)
# 断言：arr[0,index-1] 已经排序完成
def sort2(arr: list, reverse: bool = False) -> list:
    if len(arr) <= 1:
        return arr
    _arr = sort2(arr[:-1], reverse=reverse)
    if reverse:
        def comp(x, y): return x < y
    else:
        def comp(x, y): return x > y
    flag = arr[-1]
    index = find(_arr, 0, len(_arr)-1, key=flag)
    if -1 == index:
        _arr.append(flag)
    else:
        _arr.insert(index+1, flag)
    return _arr

# 查找比他小
def find(arr: list, start: int, end: int, key: int) -> int:
    if start > end:
        return -1
    if len(arr) < 2:
        return -1
    mid = int(start+(end-start)/2)
    if key >= arr[mid] and key <= arr[mid+1]:
        return mid
    if key < arr[mid]:
        return find(arr, 0, mid, key)
    if key > arr[mid]:
        return find(arr, mid, end, key)
    return -1


if __name__ == "__main__":
    arr = [3, 4, 5, 6, 1, 1, 2]
    arr = sort2(arr, reverse=True)
    print(arr)
    # print(find(arr, 0, len(arr), 5))
