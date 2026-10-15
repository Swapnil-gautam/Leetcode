class Solution:
    def reverse(self, x: int) -> int:
        digi = []
        neg = False
        if x < 0:
            neg = True
            x = -x

        while(x > 0):
            d = x%10
            digi.append(d)
            x = x//10

        new = 0
        for i in range(len(digi)):
            new = new + digi[i] * (10 **(len(digi) - 1 - i))

        INT_MAX = 2**31 - 1
        INT_MIN = -2**31

        if neg:
            new = -new

        if new < INT_MIN or new > INT_MAX:
            return 0
        
        return new


