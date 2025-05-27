class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        return ((n * (n + 1))//2) - 2*sum(i for i in range(1, n + 1) if i % m == 0)