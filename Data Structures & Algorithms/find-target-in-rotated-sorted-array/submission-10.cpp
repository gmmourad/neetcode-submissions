class Solution {
public:
    int search(vector<int>& nums, int target) {
        int first_ptr{};
        int second_ptr = static_cast<int>(nums.size()) - 1;

        while (first_ptr <= second_ptr) {
            int mid_ptr = first_ptr + (second_ptr - first_ptr) / 2;

            if (target == nums[mid_ptr])
                return mid_ptr;

            if (nums[first_ptr] <= nums[mid_ptr]) { // left half sorted
                if (target >= nums[first_ptr] && target < nums[mid_ptr])
                    second_ptr = mid_ptr - 1;
                else
                    first_ptr = mid_ptr + 1;
            }
            else { // right half sorted
                if (target > nums[mid_ptr] && target <= nums[second_ptr])
                    first_ptr = mid_ptr + 1;
                else
                    second_ptr = mid_ptr - 1;
            }
        }

        return -1;
    }
};