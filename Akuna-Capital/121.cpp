class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = INT_MIN;
        
        for (auto& price : prices){
            // minPrice untill that day
            minPrice = min(minPrice, price);
            // maxprofit untill that day
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};