class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() <=1)
            return s.length();
        std::unordered_map<char, int> curr_traversal{};
        int i{};
        int j = i+1;
        int max_length{};
        int curr_end{};
        curr_traversal[s[i]] = i;
        max_length+=1;
        while (j < s.length())
        {
            if (curr_traversal.find(s[j]) == curr_traversal.end())
            {
                if (j - i + 1> max_length)
                {
                    max_length = j-i+1;
                }
                curr_traversal[s[j]] = j;
                j++;
            }
            else if (curr_traversal[s[j]] < i)
            {
                if (j - i + 1> max_length)
                {
                    max_length = j-i+1;
                }
                 curr_traversal[s[j]] = j;
                j++;
            }
            else
            {
                curr_traversal.erase(s[i]);
                i=i+1;
                curr_traversal[s[i]] = i;
                if (j <= i)
                {
                    j = i+1;
                }
            }
        }
            return max_length;
    }

};
