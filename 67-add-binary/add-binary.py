class Solution:
    def addBinary(self, a: str, b: str) -> str:
        carry = 0
        i = len(a)-1
        j = len(b)-1
        res = ""
        while(i >= 0 or j >= 0 or carry):
            if(i>=0):
                carry = carry + int(a[i])
                i-=1
            
            if(j >= 0):
                carry = carry + int(b[j])
                j-=1
            
            res = res + str(carry%2)

            carry = carry // 2

        res = res[::-1]

        return res

