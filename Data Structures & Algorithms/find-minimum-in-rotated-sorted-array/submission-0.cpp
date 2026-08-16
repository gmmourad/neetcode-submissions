class Solution {
public:
    int findMin(vector<int> &nums) {
        int left_ptr{};
        int right_ptr = static_cast<int> (nums.size()) -1;
        int curr_ptr{};
        int min_val = nums[0];
        while (left_ptr <= right_ptr)
        {
            curr_ptr = left_ptr + (right_ptr - left_ptr)/2;
            if (nums[curr_ptr] < min_val)
            {
                min_val = nums[curr_ptr];
                right_ptr = curr_ptr -1;
            }
            else
            {
                left_ptr = curr_ptr +1;
            }
        }
        return min_val;
    }
};
