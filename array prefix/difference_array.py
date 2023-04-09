class Difference:
    def __init__(self, nums) -> None:
        self.nums = nums
        self.diff = [0]*len(self.nums)
 
    def diff(self):
        self.diff[0] = self.nums[0]
        for i in range(1, len(self.nums)):
            self.diff[i] = self.nums[i] - self.nums[i-1]
    
    def increment(self, i, j, val):
        self.diff[i] += val
        if j+1 < len(self.diff):
            self.diff[j+1] -= val
        print(self.diff)

    def result(self):
        res = [0]*len(self.diff)
        res[0] = self.diff[0]
        for i in range(1, len(self.diff)):
            res[i] = res[i-1] + self.diff[i]
        print(self.diff)
        print(res)
        assert self.diff == res
        return res

if __name__ == "__main__":
    length = 5
    updates = [[1, 3, 2], [2, 4, 3], [0, 2, -2]]
    nums = [0]*length
    diff = Difference(nums)
    for update in updates:
        i = update[0]
        j = update[1]
        val = update[2]
        diff.increment(i, j, val)
    # assert [-2, 0, 3, 5, 3] == diff.result()
    # n = 5
    # bookings = [[1,2,10],[2,3,20],[2,5,25]]
    # nums = [0]*(n)
    # diff = Difference(nums)
    # for booking in bookings:
    #     i = booking[0]-1
    #     j = booking[1]-1
    #     val = booking[2]
    #     diff.increment(i, j, val) 

    # assert [10,55,45,25,25] == diff.result()
    # n = 1000
    # nums = [0]*n
    # diff = Difference(nums)
    # trips = [[3,2,7],[3,7,9],[8,3,9]]
    # for trip in trips:
    #     i = trip[1]
    #     j = trip[2]
    #     val = trip[0]
    #     diff.increment(i, j, val)
    print(diff.result())


