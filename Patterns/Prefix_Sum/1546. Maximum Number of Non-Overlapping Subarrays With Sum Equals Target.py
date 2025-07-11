class Solution(object):
    def maxNonOverlapping(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        Hash_map={0:1}
        sum=0
        count=0
        for i in nums:
            sum+=i
            obtain=sum-target
            if obtain in Hash_map:
                count+=1
                Hash_map={0:1}
                sum=0
            if sum not in Hash_map:
                Hash_map[sum]=1
        return count

        
