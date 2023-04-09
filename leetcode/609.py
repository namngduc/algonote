from typing import List
from collections import defaultdict

class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        arr = []
        for s in paths:
            lis = s.split(" ")
            dir = lis[0]
            contents = lis[1:]
            tmp = dir + "/"
            for c in contents:
                tmp += c.replace("(", "_").replace(")", "")
                arr.append(tmp)
                tmp = dir + "/"
        # print(arr)
        map = defaultdict(list)
        for path in arr:
            value, key = path.split("_")
            map[key].append(value)
        # print(map)
        res = []
        for item in map.values():
            if len(item) > 1:
                res.append(item)
        return res


if __name__ == "__main__":
    so = Solution()
    # paths = ["root/a 1.txt(abcd) 2.txt(efgh)","root/c 3.txt(abcd)","root/c/d 4.txt(efgh)","root 4.txt(efgh)"]
    paths = ["root/a 1.txt(abcd) 2.txt(efsfgh) 3.txt(efsfgh)","root/c 3.txt(abdfcd)","root/c/d 4.txt(efggdfh)"]
    res = so.findDuplicate(paths)
    print(res)
