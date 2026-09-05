class Solution {
public:
    int characterReplacement(string s, int k) {
        int j {};
        int i{};
        int max_freq{};
        int result{};
        std::unordered_map<char, int> freq_map{};
        for (j=0; j<s.length(); j++)
        {
            freq_map[s[j]]++;
            max_freq = max(max_freq, freq_map[s[j]]);
            while ((j-i+1) - max_freq > k)
            {
                --freq_map[s[i]];
                i++;
            }
            result = max(j -i +1, result);
        }
        return result;
    }
};
