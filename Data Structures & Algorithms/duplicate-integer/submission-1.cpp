class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> set_of_nums = {};
        for (const auto & num : nums)
        {
            if (set_of_nums.find(num) !=set_of_nums.end())
                return true;
            else
            {
                set_of_nums.insert(num);
            }
        }
        return false;
    }
};