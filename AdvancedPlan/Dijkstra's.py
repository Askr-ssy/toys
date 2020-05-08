

import sys
_max = sys.maxsize

G= []
key = []    # 计算出的结果
rel = []
n = 6       # 节点数量
e = 9       # 边
z = 5       # 终点
def init_keys():
    global key,rel
    key = [_max for index in range(n)]
    rel = [0 for index in range(n)]
    key[0] = 0

def dijkstras():
    count = 0
    global G
    G = sorted(G,key = lambda x: x[0])
    while count<e:
        if (key[G[count][0]]+G[count][1][1]<key[G[count][1][0]]):
            rel[G[count][1][0]] = G[count][0]
            key[G[count][1][0]] = key[G[count][0]] + G[count][1][1]
        count+=1

    return key
if __name__ == "__main__":
    G = [
            [1-1,[2-1,7]],[1-1,[3-1,9]],[1-1,[6-1,14]],
            [2-1,[3-1,10]],[2-1,[4-1,15]],
            [3-1,[4-1,11]],[3-1,[6-1,2]],
            [4-1,[5-1,6]],
            [5-1,[6-1,9]]
        ]
    init_keys()
    dijkstras()
    print(rel)