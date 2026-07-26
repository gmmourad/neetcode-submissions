class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = 1;
        while (true)
        {
            if (j == numbers.size())
            {
                i++;
                if (i >= numbers.size() -1)
                    break;
                j = i+1;  
            }
            if ((numbers[i] + numbers[j] == target) && i !=j)
            {
                i++;
                j++;
                break;
            }
            j++;
        }
        std::vector<int> result = {i, j};
        return result;
    }
};
