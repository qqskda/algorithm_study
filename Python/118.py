class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        # List[List[int]] == [[]] ....?
        output = []
        if not numRows: return output
        output.append([1])

        for rowInd in range(1, numRows):
            row = []
            for elemInd in range(0, rowInd+1):
                if elemInd == 0 or elemInd == rowInd:
                    row.append(1)
                else:
                    row.append(output[rowInd-1][elemInd-1] + output[rowInd-1][elemInd])
            output.append(row)

        return output
