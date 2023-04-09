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

def equationsPossible(equations):
    uf = UF(26)
    for eq in equations:
        if eq[1] == '=':
            x = eq[0]
            y = eq[3]
            uf.union(ord(x) - ord('a'), ord(y) - ord('a'))
    for eq in equations:
        if eq[1] == '!':
            x = eq[0]
            y = eq[3]
            if uf.connected(ord(x) - ord('a'), ord(y) - ord('a')):
                return False
    print(chr(uf.find(ord('b')-ord('a')) + ord('a')))
    print(uf.count)
    return True

if __name__ == "__main__":
    # equations = ["a==c", "b!=a", "b==c"]
    equations = ["a==c", "x!=a", "c==b"]
    print(equationsPossible(equations))