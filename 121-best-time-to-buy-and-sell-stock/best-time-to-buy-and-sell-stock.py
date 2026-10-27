class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        n = len(prices)
        maxp = [0]*(n)
        currmax = -1
        for i in range(n):
            currmax = max(currmax, prices[n-i-1])
            maxp[n-i-1] = currmax
        
        # print(maxp)
        maxprofit = 0
        for i in range(n-1):
            maxprofit = max(maxprofit, maxp[i+1] - prices[i])

        return maxprofit
            

