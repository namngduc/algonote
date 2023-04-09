from collections import OrderedDict

class LRUCache:
    def __init__(self, capacity) -> None:
        self.cache = OrderedDict()
        self.capacity = capacity

    def get(self, key: int)-> int:
        if key not in self.cache:
            return -1
        else:
            self.cache.move_to_end(key)
            return self.cache[key]
    def put(self, key: int, value: int)-> None:
        self.cache[key] = value
        self.cache.move_to_end(key)
        if len(self.cache) > self.capacity:
            self.cache.popitem(last=False)

    def printElements(self):
        print(self.cache)


if __name__ == "__main__":
    lru_cache = LRUCache(capacity=3)
    lru_cache.put(1, 3)
    lru_cache.put(4, 5)
    lru_cache.put(7, 8)
    lru_cache.printElements()
    print(lru_cache.get(4))
    lru_cache.printElements()
    print(lru_cache.get(9))
    lru_cache.put(8, 2)
    # lru_cache.put(4, 1)
    lru_cache.printElements()
    

    



         