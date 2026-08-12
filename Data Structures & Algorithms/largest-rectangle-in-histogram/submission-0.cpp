class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        std::stack<std::pair<int, int>> s1;
        int max_area ={};
        int curr_area= {};
        for (int i=0; i<static_cast<int>(heights.size()); i++)
        {
            if (heights[i] ==0)
            {
                while(!s1.empty())
                {
                    std::pair<int, int> curr_pair = s1.top();
                    int curr_area = curr_pair.first * (i-curr_pair.second);
                    if (curr_area > max_area)
                    {
                        max_area = curr_area;
                    }
                    s1.pop();
                }
            }
            else
            {
                if (s1.empty())
                {
                    s1.push(std::make_pair(heights[i], i));
                }
                else
                {
                    if (s1.top().first == heights[i])
                    {
                        continue;
                    }
                    else if (s1.top().first > heights[i])
                    {
                        std::pair<int, int> min_pair;
                        while (!s1.empty() && s1.top().first > heights[i])
                        {
                            min_pair = s1.top();
                            int curr_area = min_pair.first * (i-min_pair.second);
                            if (curr_area > max_area)
                            {
                                max_area = curr_area;
                            }
                            s1.pop();
                        }
                        s1.push(std::make_pair(heights[i], min_pair.second));
                    }
                    else
                    {
                        s1.push(std::make_pair(heights[i], i));
                    }
                }
            }
        }
        while (!s1.empty())
        {
            std::pair<int, int> curr_pair = s1.top();
            int curr_area = curr_pair.first * (heights.size()-curr_pair.second);
            if (curr_area > max_area)
            {
                max_area = curr_area;
            }
            s1.pop();
        }
        return max_area;
    }
};
