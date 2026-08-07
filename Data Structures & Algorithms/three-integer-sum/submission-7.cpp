class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        std::vector<std::vector<int>> result{};
        std::sort(nums.begin(), nums.end());
        for (int i=0; i<static_cast<int>(nums.size()); i++)
        {
            if (i!=0 && nums[i] == nums[i-1])
                continue;
            if (nums[i] > 0)
                break;
            int first_ptr = i+1;
            int second_ptr = static_cast<int>(nums.size()) -1;
            while (first_ptr < second_ptr)
            {
                if (nums[i] + nums[first_ptr] + nums[second_ptr] < 0)
                {
                    first_ptr++;
                }
                else if (nums[i] + nums[first_ptr] + nums[second_ptr] > 0)
                {
                    second_ptr--;
                }
                else
                {
                    std::vector<int> triplet{nums[i], nums[first_ptr], nums[second_ptr]};
                    result.push_back(triplet);
                    first_ptr++;
                    second_ptr--;
                    while (first_ptr < second_ptr && nums[first_ptr] == nums[first_ptr-1])
                    {
                        first_ptr++;
                    }
                }
            }
        }
        return result;
    }
};
