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
        while (s.length())
        {
            size_t begin_pos{};
            std::string curr_string = {};
            std::string curr_length  = s.substr(begin_pos, s.find(":"));
            size_t pos_of_delim = s.find(":");
            //gives us the length of this embedded field as well s.find(":")
            decoded_result.push_back(s.substr(pos_of_delim +1, std::stoi(curr_length)));
            s = s.substr(curr_length.size() + 1 + std::stoi(curr_length), s.length() - (curr_length.size() + 1 + std::stoi(curr_length)));
        }
        return decoded_result;
    }
};
