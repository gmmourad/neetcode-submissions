class Solution {
public:
    int maxArea(vector<int>& heights) {
        int first_ptr = {};
        int second_ptr = heights.size()-1;
        int max_area = {};
        while (first_ptr < second_ptr)
        {
            int curr_height = std::min(heights[first_ptr], heights[second_ptr]);
            int curr_width = second_ptr - first_ptr;
            if (max_area  < (curr_height * curr_width))
            {
                max_area = curr_height* curr_width;
            }
            if (heights[first_ptr] == heights[second_ptr])
            {
                first_ptr++;
                second_ptr--;
            }
            else if(std::min(heights[first_ptr], heights[second_ptr]) == heights[first_ptr])
            {
                first_ptr++;
            }
            else
            {
                second_ptr--;
            }
        }
        return max_area;
        
    }
};
