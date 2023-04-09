class Heap:
    def __init__(self, comparator):
        self.arr = []
        self.comparator = comparator
    
    def print_heap(self):
        return self.arr

    def get_parent(self, k):
        return (k-1)//2
    
    def peek(self):
        return self.arr[0]
    
    def pop(self, idx):
        self.arr[idx] = self.arr[-1]
        self.arr.pop()
        self.sink(0)

    def push(self, val):
        self.arr.append(val)
        self.swim(len(self.arr)-1)
    
    def swim(self, k):
        parent = self.get_parent(k)
        if parent == -1:
            return
        if not self.comparator(self.arr[parent], self.arr[k]):
            self.arr[k], self.arr[parent] = self.arr[parent], self.arr[k]
            self.swim(parent)

    def sink(self, k):
        if k>=len(self.arr):
            return
        idx = k
        left = 2*k + 1
        right = 2*k + 2
        if left < len(self.arr) and not self.comparator(self.arr[idx], self.arr[left]):
            idx = left
        if right < len(self.arr) and not self.comparator(self.arr[idx], self.arr[right]):
            idx = right
        if idx != k:
            self.arr[k], self.arr[idx] = self.arr[idx], self.arr[k]
            self.sink(idx)

    def make_heap(self, arr):
        for i in range(len(arr)):
            self.arr.append(arr[i])
        start = (len(self.arr)-1)//2
        for k in range(start, -1, -1):
            self.sink(k)
        
if __name__ == "__main__":
    import heapq
    min_heap = Heap(lambda a, b: a<b)
    arr = [10, 7, 6, 1, 4, 3, 9, 0, 15]
    min_heap.make_heap(arr)
    heapq.heapify(arr)
    assert arr == min_heap.print_heap()
    print(min_heap.peek())
    # min_heap.pop()
    min_heap.push(-2)
    print(min_heap.print_heap())
    min_heap.pop(1)
    print(min_heap.print_heap())