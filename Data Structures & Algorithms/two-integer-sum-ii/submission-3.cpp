class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        std::vector<int> result{};
        int left_ptr = {};
        int right_ptr = static_cast<int>(numbers.size()) -1;
        while (left_ptr < right_ptr && !result.size())
        {
            if (numbers[left_ptr] + numbers[right_ptr] == target)
            {
                result.push_back(left_ptr +1);
                result.push_back(right_ptr +1);
            }
            else if (numbers[left_ptr] + numbers[right_ptr] < target)
            {
                left_ptr++;
            }
            else
            {
                right_ptr--;
            }
        }
        return result;
    }
};
