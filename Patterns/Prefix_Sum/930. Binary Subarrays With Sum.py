class Solution(object):
    def numSubarraysWithSum(self, nums, goal):
        """
        :type nums: List[int]
        :type goal: int
        :rtype: int
        """
        Hash_map={0:1}
        total=0
        sum=0
        for i in nums:
            sum+=i
            obtain=sum-goal
            if obtain in Hash_map:
                total+=Hash_map[obtain]
            if sum not in Hash_map:
                Hash_map[sum]=1
            else:
                Hash_map[sum]+=1
        return total
        
