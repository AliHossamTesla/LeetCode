class ProductOfNumbers:

    def __init__(self):
        self.st = [1]
        self.cnt = [0]

    def add(self, num: int) -> None:
        if num == 0:
            self.cnt.append(self.cnt[-1] + 1)
            self.st.append(1)
        else:
            self.st.append(num * self.st[-1])
            self.cnt.append(self.cnt[-1])

    def getProduct(self, k: int) -> int:
        if self.cnt[-1] - self.cnt[-(k + 1)] > 0:
            return 0
        else:
            return self.st[-1]//self.st[-(k + 1)]



# Your ProductOfNumbers object will be instantiated and called as such:
# obj = ProductOfNumbers()
# obj.add(num)
# param_2 = obj.getProduct(k)