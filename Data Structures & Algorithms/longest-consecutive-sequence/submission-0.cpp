class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::unordered_map<int, int> map_of_length{};
        int max_size{};
        for (const auto& num: nums)
        {
            if (!map_of_length[num])
            {
                map_of_length[num] = map_of_length[num-1] + map_of_length[num+1] +1;
                map_of_length[num - map_of_length[num-1]] = map_of_length[num];
                map_of_length[num + map_of_length[num+1]] = map_of_length[num];
                if (map_of_length[num] > max_size)
                {
                    max_size = map_of_length[num];
                }
            }
        
        }
        return max_size;
    }

};
