class Solution:
    def kidsWithCandies(self, candies: list[int], extraCandies: int) -> list[bool]:
        gret = max(candies)
        res = []
        for c in candies:
            if(c + extraCandies < gret):
                res.append(False)
            else:
                res.append(True)

        return res