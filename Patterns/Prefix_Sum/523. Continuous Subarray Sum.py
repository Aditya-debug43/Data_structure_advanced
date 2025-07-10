class Solution(object):
    def checkSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        Hash_map={0:-1}
        sum=0
        v=len(nums)
        for i in range(v):
            sum+=nums[i]
            obtain=sum%k
            if obtain in Hash_map:
                if (i-Hash_map[obtain])>=2:
                    return True
            else:
                Hash_map[obtain]=i
        return False
