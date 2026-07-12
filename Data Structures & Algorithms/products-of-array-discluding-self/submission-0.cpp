class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        
        int total_product = 1;
        int zero_count = {};
        std::vector<int> result_vec(nums.size());
        for (size_t i = 0; i<nums.size(); i++)
        {
            if (!nums[i])
            {
                ++zero_count;
                if (zero_count == 2)
                {
                    return result_vec;
                }
            }
            else
            {

                total_product = nums[i] * total_product;
            }
        }

        //std::vector<int> result_vec{};
        for (size_t i=0; i<nums.size(); i++)
        {
            if (zero_count == 1 && nums[i])
            {
                result_vec[i]= 0;
            }
            else if (zero_count == 1 && !nums[i])
            {
                result_vec[i]= total_product;
            }
            else if (!zero_count)
            {
                result_vec[i] = total_product/nums[i];
            }
        }
        return result_vec;
    }
};
