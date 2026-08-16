class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left_val = 1;
        int right_val = std::ranges::max(piles);
        int curr_val = {};
        int min_rate = std::ranges::max(piles);
        while (left_val <= right_val)
        {
            curr_val = left_val + ((right_val - left_val)/2);
            if (curr_val < min_rate)
            {
                int arr_index = {};
                int curr_hr={};
                for (size_t arr_index = 0; arr_index <piles.size(); arr_index++)
                {
                    double curr_quotient = std::ceil(static_cast<double>(piles[arr_index])/static_cast<double>(curr_val));
                    curr_hr+=static_cast<int>(curr_quotient);
                }
                if (curr_hr <= h)
                {
                    min_rate =  curr_val;
                    //lets look one for one thats less than 
                    right_val = curr_val -1;
                }
                else
                {
                    //one thats bigger
                    left_val = curr_val +1;
                }
            }
            else
            {
                right_val = curr_val -1;
            }
        }
        return min_rate;
    }
};
