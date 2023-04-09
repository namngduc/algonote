class Item:
    def __init__(self, value, weight) -> None:
        self.value = value
        self.weight = weight

w_t = [5, 3, 4, 2]
profit = [60, 50, 70, 30]
W = 5
items = []
for (i, j) in zip(profit, w_t):
    items.append(Item(i, j))
    
for item in items:
    print(item.value, item.weight)

N = len(items)

def knapsack_rc(itms, w, n):                                 # Time complexity: O(2^n)
    if (w == 0 or n == 0):
        return 0
    if itms[n-1].weight > w:
        return knapsack_rc(itms, w, n-1)
    else:
        return max(knapsack_rc(itms, w, n-1), itms[n-1].value + knapsack_rc(itms, w-itms[n-1].weight, n - 1))

res = knapsack_rc(items, W, N)
print(res)

def knapsack_memo(itms, w, n, memo):                        # Time complexity: O(N*W)
    if (w==0 or n==0):
        return 0
    if memo[n][w] != -1:
        return memo[n][w]
    if (itms[n-1].weight > w):
        result = knapsack_memo(itms, w, n-1, memo)
    else:
        result = max(knapsack_memo(itms, w, n-1, memo), itms[n-1].value + knapsack_memo(itms, w-itms[n-1].weight, n-1, memo))
    memo[n][w] = result
    return result

memo = [[-1 for _ in range(W+1)] for _ in range(N+1)]
res_memo = knapsack_memo(items, W, N, memo)
print(res_memo)

def knapsack_dp(itms, w, n):                                 # Time complexity: O(N*W), avoid stack overflow by recursive call stack
    dp = [[-1 for _ in range(w+1)] for _ in range(n+1)]
    for i in range(n+1):
        for j in range(w+1):
            if (i==0 or j==0):
                dp[i][j] = 0
            elif itms[i-1].weight > j:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = max(dp[i-1][j], itms[i-1].value + dp[i-1][j-itms[i-1].weight])
    return dp[n][w]

res_dp = knapsack_dp(items, W, N)
print(res_dp) 