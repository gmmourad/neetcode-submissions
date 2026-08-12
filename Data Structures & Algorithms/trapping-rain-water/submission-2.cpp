class Solution {
public:
    int trap(vector<int>& height) {
        int left_ptr= {};
        int right_ptr = static_cast<int>(height.size())-1;
        int curr_max_height = {};
        int total_area = {};
        while (left_ptr < right_ptr)
        {
            if (height[left_ptr] < height[right_ptr])
            {
                if (height[left_ptr] >= curr_max_height)
                {

                    curr_max_height = height[left_ptr];
                }
                else
                {
                     total_area += curr_max_height - height[left_ptr];
                }
                left_ptr++;
            }
            else
            {
                if (height[right_ptr] >= curr_max_height)
                {
                   
                    curr_max_height = height[right_ptr];
                }
                else
                {
                    total_area += curr_max_height - height[right_ptr];
                }
                right_ptr--;
            }
        }
        return total_area;
    }
    
};
