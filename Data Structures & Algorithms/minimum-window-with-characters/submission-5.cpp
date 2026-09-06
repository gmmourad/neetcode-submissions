class Solution {
public:
    string minWindow(string s, string t) {
        if (t.length() > s.length())
            return "";
        if (s == t)
            return s;
        std::unordered_map<char, int> s_map{};
        std::unordered_map<char, int> t_map{};
        int min_start_index = -1;
        int min_end_index = -1;
        int curr_start_index = -1;
        int curr_end_index = -1;
        //std::string min_string{};
        //std::string curr_string{};
        for (const auto& t_char: t)
        {
            ++t_map[t_char];
        }
        size_t i{};
        size_t j{};
        bool valid_string = false;
        while (j < s.length() && i < s.length())
        {
            while (i < s.length() && t_map.find(s[i]) == t_map.end(s[i]))
            {
                i++;
            }
            if (i == s.length())
            {
                break;
            }
            if (i > j)
            {
                j=i;
            }
            if (curr_start_index == -1)
            {
                curr_start_index = i;
            }
            if (!valid_string)
            {
                ++s_map[s[j]];
            }
            if (s_map.size() >= t_map.size())
            {
                valid_string = true;
                for (const auto& char_freq: t_map)
                {
                    if (s_map.find(char_freq.first) == s_map.end())
                    {
                        valid_string = false;
                        break;
                    }
                    else if (s_map[char_freq.first] < char_freq.second)
                    {
                        valid_string = false;
                        break;
                    }
                }
            }
            else
            {
                valid_string = false;
            }
            if (valid_string)
            {
                curr_end_index = j;
                if (min_start_index == -1 || curr_end_index - curr_start_index + 1 < min_end_index - min_start_index + 1)
                {
                    min_end_index = curr_end_index;
                    min_start_index = curr_start_index;
                }
                if (!--s_map[s[i]])
                {
                    s_map.erase(s[i]);
                }
                curr_start_index = -1;
                i++;
            }
            else
            {
                j++;
            }
        }
        if (min_start_index == -1)
            return "";
        else
            return s.substr(min_start_index, min_end_index - min_start_index + 1);        

    }
};
