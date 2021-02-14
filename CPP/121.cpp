class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Rule: Cannot buy the stock on the last day
        // Do not have to calculate each profit

        int maxProfit = 0;
        int minPrice = INT_MAX;

        for (int day = 0; day < prices.size(); ++day){
            // minimum market price untill the day
            minPrice = min(minPrice, prices[day]);
            // maximum profit available untill the day
            maxProfit = max(maxProfit, prices[day] - minPrice);
        }

        return maxProfit;
    }
};
