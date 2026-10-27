class Solution:
    def findWinners(self, matches: list[list[int]]) -> list[list[int]]:
        winners = {}
        lossers = {}

        n = len(matches)

        for i in range(n):
            w = matches[i][0]
            l = matches[i][1]

            winners[w] = winners.get(w, 0) + 1
            lossers[l] = lossers.get(l, 0) + 1


        for wkey, wvalue in winners.items():
            if(lossers.get(wkey) != None):
                winners[wkey] = 0

        resw = []
        for wkey, wvalue in winners.items():
            if(wvalue > 0):
                resw.append(wkey)
            
        resl = []
        for lkey, lvalue in lossers.items():
            if(lvalue == 1):
                resl.append(lkey)

        resw.sort()
        resl.sort()

        return [resw, resl]

            
            



