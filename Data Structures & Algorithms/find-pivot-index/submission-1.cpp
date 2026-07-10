class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total_sum = {};
        int left_sum = {};
        for (const auto & num: nums)
        {
            total_sum +=num;
        }
        for (int i =0; i<nums.size(); i++)
        {
            if (left_sum == (total_sum - (left_sum + nums[i])))
            {
                return i;
            }
            left_sum += nums[i];
        }
        return -1;
    }
};