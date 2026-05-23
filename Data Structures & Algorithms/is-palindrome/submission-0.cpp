class Solution {
public:
    bool isPalindrome(string s) {
        bool retVal = true;
        std::stack<char> s_stack;
        for (size_t i = 0; i<s.length(); i++)
        {
            if (std::isalnum(s[i]))
            {
                s_stack.push(toupper(s[i]));
            }
        }
        for (size_t i = 0; i< s.length(); i++)
        {
            if (std::isalnum(s[i]))
            {
                if (s_stack.top() != toupper(s[i]))
                {
                    retVal = false;
                }
                s_stack.pop();
            }
        }
        return retVal;
        
    }
};
