class Solution {
public:
    bool isPalindrome(string s) {
        bool retVal = true;
        size_t leftIndex =0;
        size_t rightIndex = s.length() -1;
        while (leftIndex < rightIndex)
        {
            if (isalnum(s[leftIndex]) && isalnum(s[rightIndex]))
            {
                if (toupper(s[leftIndex]) != toupper(s[rightIndex]))
                {
                    return false;
                }
                else
                {
                    leftIndex++;
                    rightIndex--;
                }
            }
            else if (isalnum(s[leftIndex]) && !isalnum(s[rightIndex]))
            {
                rightIndex--;
            }
            else if (!isalnum(s[leftIndex]) && isalnum(s[rightIndex]))
            {
                leftIndex++;
            }
            else
            {
                leftIndex++;
                rightIndex--;
            }
        }
        return retVal;
    }
};
