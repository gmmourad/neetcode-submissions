class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> s1;
        vector<int> result_vector(temperatures.size());
        for (size_t i=0; i<temperatures.size(); i++)
        {
            while (!s1.empty() && temperatures[i] > temperatures[s1.top()])
            {
                result_vector[s1.top()] = i - s1.top();
                s1.pop();
            }
            s1.push(i);
        }
        return result_vector;

    }
};
