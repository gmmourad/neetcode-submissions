class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1)
            return 0;
        int min_buy_date = 0; 
        //int max_sell_date = 1;
        int max_profit{};
        int i = {};
        int j = 1;

        while(j < prices.size())
        {
            if (prices[i] < prices[min_buy_date])
            {
                min_buy_date = i;
            }
            if (prices[j] - prices[min_buy_date] > max_profit)
            {
                max_profit = prices[j] - prices[min_buy_date];
            }
            i++;
            j++;
        }
        return max_profit;
    }
};
