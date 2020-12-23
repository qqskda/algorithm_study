class Solution:
    def longestLine(self, M: List[List[int]]) -> int:
        # defaultdict is under collections library
        row = collections.defaultdict(int)
        col = collections.defaultdict(int)
        ad = collections.defaultdict(int)
        dd = collections.defaultdict(int)
        mRes = 0
        # There is no need of enumeate(M)
        # Because the value is always 0 or 1 
        for i in range(len(M)):
            for j in range(len(M[0])):
                if not M[i][j]:
                    row[i] = col[j] = ad[j + i] = dd [j - i] = 0
                else:
                    row[i] += 1
                    col[j] += 1
                    ad[j + i] += 1
                    dd[j - i] += 1
                    mRes = max(mRes, row[i], col[j], ad[j+i], dd[j-i])
        return mRes
