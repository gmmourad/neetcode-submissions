class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left_arr{};
        int right_arr = static_cast<int>(matrix.size()) -1;
        while (left_arr <= right_arr)
        {
            int mid_arr = left_arr + (right_arr - left_arr)/2;
            if (matrix[mid_arr][0] <= target && matrix[mid_arr][matrix[mid_arr].size()-1] >=target)
            {
                int left_ptr{};
                int right_ptr = static_cast<int>(matrix[mid_arr].size()) -1;
                while (left_ptr<= right_ptr)
                {
                    int mid_ptr = left_ptr + (right_ptr  - left_ptr)/2;
                    if (matrix[mid_arr][mid_ptr] == target)
                    {
                        return true;
                    }
                    else if (matrix[mid_arr][mid_ptr] > target)
                    {
                        right_ptr = mid_ptr -1;
                    }
                    else
                    {
                        left_ptr = mid_ptr +1;
                    }
                }
                return false;
            }
            else if (matrix[mid_arr][matrix[mid_arr].size()-1] <target)
            {
                left_arr = mid_arr +1;
            }
            else
            {
                right_arr = mid_arr -1;
            }
        }
        return false;
    }
};
