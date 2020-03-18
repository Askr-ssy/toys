'''
算法导论2.3.7 
O(nlgn) 在集合S中寻找综合x的两个数字
'''


def find(arr, s, e, k):
    if s > e:
        return -1
    m = (s+e)//2
    if arr[m] == k:
        return m
