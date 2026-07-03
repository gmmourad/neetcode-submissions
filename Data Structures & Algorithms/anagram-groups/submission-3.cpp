class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::unordered_map<string, size_t> map_of_freq{};
        std::vector<std::vector<std::string>> result_vector{};
        for (const auto& str: strs)
        {
            std::vector<int> v1(26, 0);
            for (const auto & chr: str)
            {
                ++v1[static_cast<int>(chr) - static_cast<int>('a')];
            }
            std::string string_encoded{};
            for (size_t i =0; i<v1.size(); i++)
            {
                string_encoded+=std::to_string(i) + ":" + std::to_string(v1[i]) + ":";
            }
            if (map_of_freq.find(string_encoded) != map_of_freq.end())
            {
                result_vector[map_of_freq[string_encoded]].push_back(str);
            }
            else
            {
                std::vector<std::string> new_vector = {str};
                result_vector.push_back(new_vector);
                map_of_freq[string_encoded] = result_vector.size()-1;
            }
        }
        return result_vector;
    }
};
