class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<vector<int>> result{};
        std::sort(nums.begin(), nums.end());
        for (size_t i =0; i< nums.size(); i++)
        {
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i-1] == nums[i])
                continue;
            int j = i+1;
            int k = nums.size()-1;
            while (j < k)
            {
                if (nums[i] + nums[j] + nums[k] < 0)
                {
                    j++;
                }
                else if (nums[i] + nums[j] + nums[k] > 0)
                {
                    k--;
                }
                else
                {
                    std::vector<int> temp_vector {nums[i], nums[j], nums[k]};
                    result.push_back(temp_vector);
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j-1])
                    {
                        j++;
                    }
                }
            }
        }
        return result;

    }
};
