class Solution {
public:

    string encode(vector<string>& strs) {
        std::string network_string{};
        //embed the length into the string 
        for (const auto & str: strs)
        {
            network_string += std::to_string(str.length()) + ":"; 
            network_string += str; 
        }
        return network_string;

    }

    vector<string> decode(string s) {
        std::vector<string> decoded_result{};
        size_t pos{};
        while (pos < s.length())
        {
            size_t pos_of_delim = s.find(":", pos);
            std::string curr_length = s.substr(pos,pos_of_delim-pos);
            //gives us the length of this embedded field as well s.find(":")
            decoded_result.push_back(s.substr(pos_of_delim +1, std::stoi(curr_length)));
            pos += curr_length.size() + 1 + std::stoi(curr_length);
        }
        return decoded_result;
    }
};
