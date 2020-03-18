def sort(arr: list, reverse: bool = False) -> list:
    if len(arr) <= 1:
        return arr
    if reversed:
        def comp(x, y): return x < y
    else:
        def comp(x, y): return x > y
    for index in range(0, len(arr):         # 断言: arr[index]为当前[0,index]中最大|最小的元素
        for j in range(index, len(arr)):
            if comp(arr[j], arr[index]):
                arr[j], arr[index]=arr[index], arr[j]
    return arr

# O(n^2)
if __name__ == "__main__":
    print(sort([1, 6, 7, 3, 4, 2]))
