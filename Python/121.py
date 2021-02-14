class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        maxProfit = 0
        minPrice = sys.maxsize

        for value in prices:
            minPrice = min(minPrice, value)
            maxProfit = max(maxProfit, value - minPrice)

        return maxProfit
