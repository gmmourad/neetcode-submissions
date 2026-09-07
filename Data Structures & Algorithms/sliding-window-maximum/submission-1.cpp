class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::vector<int> result{};
        std::deque<int> curr_window{};
        size_t curr_k = k-1;
        size_t i = 0;
        //int curr_max = nums[0];
        while (curr_k < nums.size())
        {
            size_t j{};
            if (i ==0)
            {
                j =i;
            }
            else
            {
                j = curr_k;
            }
            while (j <= curr_k)
            {
                if (!curr_window.empty() && nums[j] >= nums[curr_window.back()])
                {
                    while (!curr_window.empty() && nums[j] >= nums[curr_window.back()])
                    {
                        curr_window.pop_back();
                    }
                    curr_window.push_back(j);
                }
                else
                {
                    curr_window.push_back(j);
                }
                j++;
            }
            result.push_back(nums[curr_window.front()]);
            i++;
            curr_k++;
            if (curr_window.front() < i)
            {
                curr_window.pop_front();
            }
        }
        return result;
    }
};
