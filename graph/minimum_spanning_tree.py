class UF:
    def __init__(self, n) -> None:
        self.count = n
        self.parent = [-1]*n
        self.size = [-1]*n
        for i in range(n):
            self.parent[i] = i
            self.size[i] = 1
    def union(self, p, q):
        rootP = self.find(p)
        rootQ = self.find(q)
        if (rootP == rootQ): return
        if self.size[rootP] > self.size[rootQ]:
            self.parent[rootQ] = rootP
            self.size[rootP] += self.size[rootQ]
        else:
            self.parent[rootP] = rootQ
            self.size[rootQ] += self.size[rootP]
        self.count -= 1
    def connected(self, p, q):
        rootP = self.find(p)
        rootQ = self.find(q)
        return rootP==rootQ

    def find(self, x):
        while (self.parent[x] != x):
            self.parent[x] = self.parent[self.parent[x]]
            x = self.parent[x]
        return x

def MST(n, edges):
    uf = UF(n)
    ans = 0
    for edge in edges:
        x = edge[0]
        y = edge[1]
        w = edge[2]
        if uf.find(x) == uf.find(y): continue
        uf.union(x, y)
        ans += w
    if uf.count == 1:
        return ans

if __name__ == "__main__":
    # n = 9
    # edges = [[0, 1, 4], [1, 2, 8], [2, 3, 7], [3, 4, 9], [4, 5, 10], 
    #         [5, 3, 14], [2, 5, 4], [5, 6, 2], [6, 8, 6], [8, 2, 2], [6, 7, 1], [7, 8, 7], [7, 1, 11], [7, 0, 8]]
    points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
    n = len(points)
    graph = []
    for i in range(len(points)):
        for j in range(i+1, len(points)):
            w = abs(points[j][1] - points[i][1]) + abs(points[j][0] - points[i][0])
            graph.append([i, j, w])
    # print(graph)
    graph.sort(key=lambda item: item[2])
    print(MST(n, graph))
    # edges.sort(key=lambda item: item[2])
    # print(MST(n, edges))

