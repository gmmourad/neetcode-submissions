class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, int> freq_map {};
        std::vector<int> result {};
        for (const auto& number : nums)
        {
            if (freq_map.find(number) == freq_map.end())
            {
                freq_map.insert(std::make_pair(number, int{}));
            }
            freq_map[number]++;
        }
        std::priority_queue<std::pair<int, int>> freq_queue;
        for (const auto& number_freq_pair: freq_map)
        {
            freq_queue.push(std::make_pair(number_freq_pair.second, number_freq_pair.first));
        }
        for (size_t i={}; i<k && freq_queue.size(); i++)
        {
            int curr_element = freq_queue.top().second;
            result.push_back(curr_element);
            freq_queue.pop();
        }
        return result;

    }
};
