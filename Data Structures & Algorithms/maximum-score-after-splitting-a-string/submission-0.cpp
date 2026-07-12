class Solution {
public:
    int maxScore(string s) {
        int curr_max = {};
        int left_score = {};
        for (size_t i = 0; i<s.length(); i++)
        {
            if (s[i] == '0')
            {
                left_score++;
            }
        }
        int right_score = {};
        for (int i=s.length() -1; i >=1; i--)
        {
            if (s[i] == '1')
            {
                right_score++;
            }
            else
            {
                left_score--;
            }
            if (right_score + left_score > curr_max)
            {
                curr_max = right_score + left_score;
            }
        }
        return curr_max;
    }
};