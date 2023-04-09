from typing import List

class Node:
    def __init__(self, data, left=None, right=None):
        self.val = data
        self.left = left
        self.right = right
class Tree:
    def __init__(self) -> None:
        self.stack = []

    def createTree(self, arr, i , n):
        if i>n: return None
        root = Node(arr[i])
        root.left = self.createTree(arr, 2*i+1, n)
        root.right = self.createTree(arr, 2*i+2, n)
        return root

    def iterative_inorder(self, root):
        visited = Node(-1)
        self.pushLeftBranch(root)
        while self.stack:
            p = self.stack[-1]
            if (not p.left or p.left == visited) and p.right != visited:
                # In-order traversal put at here
                # print(p.val, end="\t")
                self.pushLeftBranch(p.right)
            if (not p.right or p.right == visited):
                # Post-order traversal put at here
                print(p.val, end="\t")
                visited = self.stack.pop()

    def pushLeftBranch(self, p):
        while p:
            # Pre-order traversal put at here
            self.stack.append(p)
            p = p.left

    
arr = [1,2, 3, None, 5, 6]
tree = Tree()
root = tree.createTree(arr, 0, (len(arr)-1))
tree.iterative_inorder(root)
        