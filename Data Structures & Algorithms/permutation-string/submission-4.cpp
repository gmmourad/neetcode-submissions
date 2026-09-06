class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.length() < s1.length())
            return false;
        std::unordered_map<char, size_t> s1_freq_map{};
        std::unordered_map<char, size_t> s2_freq_map{};
        for (const auto& s1_char: s1)
        {
            ++s1_freq_map[s1_char];
        }
        size_t i{};
        size_t j =i;
        while (j < s2.length())
        {
            ++s2_freq_map[s2[j]];
            if (s1_freq_map.find(s2[j])==s1_freq_map.end())
            {
                s2_freq_map.clear();
                j++;
                i=j;
            }
            else
            {
                j++;
            }
            if (j-i == s1.length())
            {
                if (s1_freq_map == s2_freq_map)
                    return true;
                else
                {
                    --s2_freq_map[s2[i]];
                    if (s2_freq_map[s2[i]] == 0)
                    {
                        s2_freq_map.erase(s2[i]);
                    }
                    i++;
                }
            }
        
        } 
        return false;
    }
};
