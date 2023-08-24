class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_stock =prices[0];
        int profit=0;

        for(int i=1;i<prices.size();i++)
        {
            profit = max(prices[i]-min_stock,profit);
            min_stock = min(min_stock,prices[i]);
        }

        return profit;
    }
};