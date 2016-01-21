二分查找差值，用一个哈希表映射下标
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mapping;
        vector<int> vec;
        for (int i = 0; i < nums.size(); i++)
        	mapping[nums[i]] = i;
        for (int i = 0; i < nums.size(); i++)
        {
        	int gap = target - nums[i];
        	if (mapping.find(gap) != mapping.end() && mapping[gap] != 0)
        	{
        		vec.push_back(i + 1);
        		vec.push_back(mapping[gap] + 1);
        		break;
        	}
        }
        return vec;
    }
};