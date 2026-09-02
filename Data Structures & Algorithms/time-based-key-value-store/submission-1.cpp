class TimeMap {
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        theTimeMap[key].push_back(std::make_pair(timestamp, value));
    }
    
    string get(string key, int timestamp) {
        std::string result_string{};
        if (theTimeMap.find(key) == theTimeMap.end())
            return result_string;
        int left_ptr {};
        int right_ptr = static_cast<int>(theTimeMap[key].size())-1;
        int min_index {};
        if (theTimeMap[key][left_ptr].first > timestamp)
            return result_string;
        if (theTimeMap[key][right_ptr].first < timestamp)
            return theTimeMap[key][right_ptr].second;
        while (left_ptr <=right_ptr)
        {
            int curr_ptr = left_ptr + (right_ptr - left_ptr)/2;
            if (theTimeMap[key][curr_ptr].first == timestamp)
                return theTimeMap[key][curr_ptr].second;
            else
            {
                if (theTimeMap[key][curr_ptr].first < timestamp)
                {
                    left_ptr = curr_ptr + 1;
                }
                else
                {
                    right_ptr = curr_ptr -1;
                }
            } 
        }
        if (right_ptr >=0 && left_ptr <= theTimeMap[key].size() -1)
        {
            if (theTimeMap[key][left_ptr].first > timestamp && theTimeMap[key][right_ptr].first < timestamp)
                return theTimeMap[key][right_ptr].second;
        }
        return result_string;
    }

private:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> theTimeMap{};
    

};
