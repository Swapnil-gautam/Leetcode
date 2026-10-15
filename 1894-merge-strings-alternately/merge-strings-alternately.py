class Solution:
    def mergeAlternately(self, word1: str, word2: str) -> str:
 
        res = ""
        count = 0
        for i in range(0, len(word1)):
            if(i < len(word2)):
                res = res + word1[i] + word2[i]
            else:
                res = res + word1[i:]
                break
            # print("res: ", res)
            count = count + 1

        # print("count: ", count)
        if(count < len(word2)):
            res = res + word2[count:]

        return res
        
