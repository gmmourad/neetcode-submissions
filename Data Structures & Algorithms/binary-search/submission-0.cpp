class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left_ptr= {};
        int right_ptr = static_cast<int>(nums.size()) -1;
        while (left_ptr<=right_ptr)
        {
            int curr_element = left_ptr + (right_ptr - left_ptr)/2;
            if (target == nums[curr_element])
            {
                return curr_element;
            }
            else if (nums[curr_element] > target)
            {
                right_ptr = curr_element -1;
            }
            else
            {
                left_ptr = curr_element +1;
            }
        }
        return -1;
    }
};
