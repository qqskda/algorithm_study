class Solution {
public:
    int climbStairs(int n) {
        if (n < 4) return n;
        int oneLower = 3;
        int twoLower = 2;
        int curr = 0;
        for (int i = 4; i <= n; ++i){
            curr = oneLower + twoLower;
            twoLower = oneLower;
            oneLower = curr;
        }
        return curr;
    }
};

/*
Asking diff num of taking steps: calculate how many diff steps untill that stair step.
currLevel = oneLower + twoLower

*/