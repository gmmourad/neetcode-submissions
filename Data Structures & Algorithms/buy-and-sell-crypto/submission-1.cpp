class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxDiff = 0;
        for (size_t i = prices.size() - 1; i>0 ; i--)
        {
            for (size_t j =0; j<i; j++)
            {
                int currDiff = 0;
                if (prices[i] > prices[j])
                {
                    currDiff = prices[i] - prices[j];
                    if (maxDiff < currDiff)
                    {
                        maxDiff = currDiff; 
                    }
                }
            }
        }
        return maxDiff;
    }
};
