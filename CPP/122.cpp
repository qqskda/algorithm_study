class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        for (size_t day = 1; day < prices.size(); ++day){
            if (prices[day] > prices[day-1]){
                // It may seem like violating the rule: Cannot buy and sell on the same day.
                // when it is [1,2,3,4,5] constantly increasing.
                // However, the actual transaction will be [1,5] which has the same profit amount.
                profit += prices[day] - prices[day-1];
            }
        }

        return profit;
    }
};
