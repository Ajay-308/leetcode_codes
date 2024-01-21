class Solution:
    def rob(self, nums: List[int]) -> int:
        cur=0
        prev=0
        for i in range(len(nums)):
            temp=cur
            cur=max(cur,prev+nums[i])
            prev=temp
        return cur


//checm by dry run
