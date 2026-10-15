class Solution:
    def reverseVowels(self, s: str) -> str:
        isvovel = []
        vovels = []
        for i in range(len(s)):
            if(s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u' or 
                s[i] == 'A' or s[i] == 'E' or s[i] == 'I' or s[i] == 'O' or s[i] == 'U'):
                isvovel.append(True)
                vovels.append(s[i])
            else:
                isvovel.append(False)

        vovels.reverse()
        res = ""
        count = 0
        for i in range(len(s)):
            if(isvovel[i] == True):
                res = res + vovels[count] 
                count = count + 1
            else:
                res = res + s[i]

        return res