class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        size_t max_val = grid.size() * grid.size();
        std::unordered_set<int> seen{};
        std::unordered_set<int> set_of_vals{};
        std::vector<int> result_vector(2);
        for (size_t i =1; i<=max_val; i++)
        {
            set_of_vals.insert(i);
        }
        for (const auto & row: grid)
        {
            for (const auto & element: row)
            {
                if (seen.find(element) != seen.end())
                {
                    result_vector[0] = element;
                }
                else
                {
                    seen.insert(element);
                }
                set_of_vals.erase(element);
            }
        }
        for (const auto & val: set_of_vals)
        {
            result_vector[1] = val;
            return result_vector;
        }
    }
};