class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        left = []
        right = []
        lmul = 1
        rmul = 1
        left.append(1)
        for i in range(len(nums)):
            lmul = lmul * nums[i]
            left.append(lmul)
            rmul = rmul * nums[len(nums) - 1 - i]
            right.append(rmul)
        
        right.reverse()
        right.append(1)

        out = []
 
        for i in range(1,len(left)):
            out.append(left[i-1]*right[i])

        return out