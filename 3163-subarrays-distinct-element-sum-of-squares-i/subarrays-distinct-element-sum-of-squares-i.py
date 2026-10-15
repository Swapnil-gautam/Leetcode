class Solution:
    def sumCounts(self, nums: List[int]) -> int:
        res = []
        for i in range(0, len(nums)):
            for j in range(i, len(nums)):
                temp = nums[i:j+1]
                res.append(len(set(temp))**2)
        
        return sum(res)
                

        