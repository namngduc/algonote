class Solution:
    def divide(self, arr, lo, hi):
        if lo==hi: return [arr[lo]]
        mid = lo + (hi-lo)//2
        nums1 = self.divide(arr, lo, mid)
        nums2 = self.divide(arr, mid+1, hi)
        return self.merge(nums1, nums2)
    
    def merge(self, nums1, nums2):
        nums = []
        i, j = 0, 0
        m, n = len(nums1), len(nums2)
        while i < m and j < n:
            if nums1[i] < nums2[j]:
                nums.append(nums1[i])
                i+=1
            else:
                nums.append(nums2[j])
                j+=1
        if i < m:
            nums += nums1[i:]
        if j < n:
            nums += nums2[j:]
        return nums


if __name__ == "__main__":
    so = Solution()
    arr = [1, 4, 3, 2, 5]
    lo, hi = 0, len(arr)-1
    print(so.divide(arr, lo, hi))

