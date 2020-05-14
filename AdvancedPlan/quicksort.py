# 快速排序


def quick_sort(data, start, end):
    if start >= end:
        return
    if len(data) == 0:
        return
    l = start+1
    r = end
    key = data[start]
    while True:
        while l <= r and data[l] <= key:
            l += 1
        while l <= r and data[r] >= key:
            r -= 1
        if l >= r:
            break
        data[l], data[r] = data[r], data[l]
    data[r], data[start] = data[start], data[r]
    quick_sort(data, start, r-1)
    quick_sort(data, r+1, end)

def sort(data: list) -> list:
    data = [2, 12, 4, 215, 123, 15, 2132, 1123]
    data = [632, 412, 51, 23, 51, 12, 12, 412, 31]
    quick_sort(data, 0, len(data)-1)
    return data


if __name__ == '__main__':
    a = sort([5, 4, 3, 2, 1])  # -> [1,2,3,4,5]
    print(a)
