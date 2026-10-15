class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        freq = {}
        i = 0
        j = 0
        n = len(s)
        res = 0

        while(j < n):
            freq[s[j]] = freq.get(s[j], 0) + 1
            while(freq[s[j]] > 1):
                freq[s[i]] = freq[s[i]] - 1
                i = i + 1
            res = max(res, j - i + 1)
            j += 1

        return res
