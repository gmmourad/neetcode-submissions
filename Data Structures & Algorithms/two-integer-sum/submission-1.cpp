class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
         std::unordered_map<int, int> valToIndexMap;
        for (size_t i = 0; i<nums.size(); i++)
        {
            if (valToIndexMap.find(target - nums[static_cast<int>(i)]) != valToIndexMap.end())
            {
                return std::vector<int> {valToIndexMap[target-nums[static_cast<int>(i)]], static_cast<int>(i)};
            }
            if (valToIndexMap.find(nums[i]) != valToIndexMap.end())
            {
                continue;
            }
            else
            {
                valToIndexMap.insert(std::make_pair(nums[i], static_cast<int>(i)));
            }
        }
        return std::vector<int> {};
    }
};
