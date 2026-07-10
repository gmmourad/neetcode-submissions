class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        size_t size_of_nums = nums.size();
        std::vector<int> left_array(size_of_nums);
        std::vector<int> right_array(size_of_nums);
        for (int i=0; i< nums.size(); i++)
        {
            if (i==0)
            {
                left_array[i] = 0;
            }
            else
            {
                left_array[i] = nums[i-1] + left_array[i-1];
            }
        }
        for (int i=nums.size() -1; i>=0; i--)
        {
            if (i == nums.size() -1)
            {
                right_array[i] = 0;
            }
            else
            {
                right_array[i] = nums[i+1] + right_array[i+1];
            }
        }
        for (int i=0; i<nums.size(); i++)
        {
            if (right_array[i] == left_array[i])
                return i;
        }
        return -1;

    }
};