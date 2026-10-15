class Solution:
    def increasingTriplet(self, nums: list[int]) -> bool:
        n = len(nums)

        minnum = nums[0]
        minback = [minnum]

        maxnum = nums[-1]
        maxfront = [maxnum]
        

        for i in range(1, n):
            minnum = min(minnum, nums[i])
            minback.append(minnum)
            maxnum = max(maxnum, nums[n-1-i])
            maxfront.append(maxnum)


        maxfront.reverse()
        # print("minback: ", minback)
        # print("maxfront: ", maxfront)

        for i in range(1, n-1):
            if(minback[i-1] < nums[i] and nums[i] < maxfront[i+1]):
                return True


        return False

