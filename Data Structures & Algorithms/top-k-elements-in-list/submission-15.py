class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        occurences = dict()
        total_occurences = dict()
        for i in range(len(nums)):
            val = nums[i]
            if val in occurences:
                occurences[val] += 1
                num_occurs = occurences[val]
                if num_occurs in total_occurences:
                    total_occurences[num_occurs].append(val)
                else:
                    total_occurences[num_occurs] = [val]
                
                total_occurences[num_occurs - 1].remove(val)
            else:
                occurences[val] = 1
                if 1 in total_occurences:
                    total_occurences[1].append(val)
                else:
                    total_occurences[1] = [val]
        
        print(total_occurences)
        occur_ind = max(total_occurences)
        print(total_occurences[occur_ind])
        vals = []
        i = 0
        while  k > 0:
            if i < len(total_occurences[occur_ind]):
                vals.append(total_occurences[occur_ind][i])
                k -= 1
                i += 1
            else:
                occur_ind -= 1
                i = 0
        return vals