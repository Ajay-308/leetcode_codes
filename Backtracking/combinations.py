class Solution:
    def combine(self, n, k):
        ans = []
        cur = []

        self.back(ans, cur, n, k, 1)

        return ans

    def back(self, ans, cur, n, k, ind):
        if k == 0:
            ans.append(cur[:]) 
            return

        for i in range(ind, n + 1):
            cur.append(i)
            self.back(ans, cur, n, k - 1, i + 1)
            cur.pop()
