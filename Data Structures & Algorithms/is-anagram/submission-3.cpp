class Solution {
public:
    bool isAnagram(string s, string t) {
        if (t.length() != s.length())
            return false;
        std::unordered_map<char, int> s_map;
        for (const auto & s_char: s)
        {
            if(s_map.find(s_char) == s_map.end())
            {
                s_map.insert(std::make_pair(s_char, 1));
            }
            else
            {
                s_map[s_char]++;
            }
        }

        std::unordered_map<char, int> t_map;
        for (const auto & t_char: t)
        {
            if (s_map.find(t_char) == s_map.end())
                return false;
            else
            {
                if(t_map.find(t_char) == t_map.end() )
                {
                    t_map.insert(std::make_pair(t_char, 1));
                }
                else
                {
                    t_map[t_char]++;
                    if (t_map[t_char] > s_map[t_char])
                        return false;
                }
            }
        }

        for (const auto & s_char: s)
        {
            if (s_map[s_char] != t_map[s_char])
                return false;
        }
        return true;
    }
};
