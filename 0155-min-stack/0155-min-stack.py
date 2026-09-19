class MinStack:
    def __init__(self):
        self._stack = []

    def push(self, val: int) -> None:
        min_val = self.getMin()

        if min_val is None or val < min_val:
            min_val = val

        self._stack.append([val, min_val])

    def pop(self) -> None:
        if self._stack:
            self._stack.pop()

    def top(self) -> int:
        if self._stack:
            return self._stack[-1][0]
        else:
            return None

    def getMin(self) -> int:
        if self._stack:
            return self._stack[-1][1]
        else:
            return None

# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(value)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()