class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = nums[0], currSub = nums[0];
        
        // Kadane's Algorithm
        for (int i = 1; i < nums.size(); ++i){
            int num = nums[i];
            currSub = max(num, currSub+num);
            maxSub = max(maxSub, currSub);

        }
        return maxSub;
    }
};

/*
1. currSubArr
2. maxSubArr
3. currNum
if currNum > maxSubArr -> reset to currNum
if currSubArr > maxSubArr = update
*/