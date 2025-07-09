class Solution(object):
    def subarraysDivByK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        Hash_map={0:1}
        count=0
        sum=0
        for i in nums:
            sum+=i
            obtain=sum%k
            if obtain in Hash_map:
                count+=Hash_map[obtain]
                Hash_map[obtain]+=1
            else:
                Hash_map[obtain]=1
            
        return count
            
        
        
