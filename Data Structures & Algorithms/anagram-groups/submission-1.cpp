class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, size_t> map_of_freq{};
        std::vector<std::vector<std::string>> result_vector{};
        for (const auto& str: strs)
        {
            std::string curr_string = str;
            std::sort(curr_string.begin(), curr_string.end());
            if (map_of_freq.find(curr_string) != map_of_freq.end())
            {
                result_vector[map_of_freq[curr_string]].push_back(str);
            }
            else
            {
                std::vector<std::string> new_vector = {str};
                result_vector.push_back(new_vector);
                map_of_freq[curr_string] = result_vector.size()-1;
            }
        }
        return result_vector;
    }
};
