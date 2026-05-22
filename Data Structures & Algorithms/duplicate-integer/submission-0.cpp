class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> setOfNums;
        for (const auto& itr: nums)
        {
            if (setOfNums.find(itr) != setOfNums.end())
            {
                return true;
            }
            else
            { 
                setOfNums.insert(itr);
            }
        }
        return false;
    }
};