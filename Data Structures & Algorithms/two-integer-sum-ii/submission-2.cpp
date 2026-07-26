class Solution {
    public:
        vector<int> twoSum(vector<int>& numbers, int target) {
                int i =0; 
                int j =numbers.size()-1;
                while (numbers[j] + numbers[i] != target)
                {
                        if (numbers[j] + numbers[i] < target)
                        {
                                i++;
                        }
                        else if (numbers[j] + numbers[i] > target)
                        {
                                j--;
                        }
                }
                i++;
                j++;
                std::vector<int> result {i, j};
                return result;
        };
};
                        