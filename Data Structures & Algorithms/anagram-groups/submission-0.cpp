class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        std::unordered_map<size_t, std::unordered_map<char, size_t>> map_of_freq{};
        std::vector<std::vector<std::string>> result_vector;
        
        //O(N^2) worse case if there are no anagrams
        for (auto& str: strs)
        {
            std::unordered_map<char, size_t> curr_map;
            for (auto & str_char : str)
            {
                str_char = tolower(str_char);
                if (curr_map.find(str_char) == curr_map.end())
                {
                    curr_map[str_char] = {};

                }
                ++curr_map[str_char];
            }
            curr_map['\0'] = 1;
            bool insertion_performed = false;
            for (size_t i =0; i<result_vector.size(); i++)
            {
                if (map_of_freq[i] == curr_map)
                {
                    result_vector[i].push_back(str);
                    insertion_performed = true;
                    break;
                }
            }
            if (!insertion_performed)
            {
                map_of_freq[result_vector.size()] =  curr_map;
                std::vector<std::string> newVector = {};
                newVector.push_back(str);
                result_vector.push_back(newVector);                  
            }
        }
        return result_vector;
    }
};
