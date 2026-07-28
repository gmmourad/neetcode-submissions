class Solution {
public:
    int maxArea(vector<int>& heights) {
        int max_area {};
        int i{};
        int j = static_cast<int>(heights.size()) -1;
        while (i < j)
        {
            if ((std::min(heights[i], heights[j])) * (j-i) > max_area)
            {
                max_area = std::min(heights[i], heights[j]) * (j-i);
            }
            if (std::min(heights[i], heights[j]) == heights[i])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return max_area;
    }
};
