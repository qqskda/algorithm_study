class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        for (int i = 2; i < n; ++i){
            cost[i] += min(cost[i-1], cost[i-2]); // Be aware it is adding
        }

        return min(cost[n-1], cost[n-2]);
    }
};

/*
We do not know if the decision will be the best in overall -> DP

Subproblem;
Adding up the cost when u climb so that each index represens the min cost to get there
*/
