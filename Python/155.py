class MinStack:

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.st = []


    def push(self, x: int) -> None:
        if len(self.st) == 0:
            self.st.append([x,x]);
        else:
            if self.st[-1][1] > x:
                self.st.append([x,x])
            else:
                self.st.append([x, self.st[-1][1]])

    def pop(self) -> None:
        self.st.pop()

    def top(self) -> int:
        return self.st[-1][0]

    def getMin(self) -> int:
        return self.st[-1][1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()
