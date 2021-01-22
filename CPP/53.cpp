class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int inc = nums[0], maxSum = nums[0];

        for (auto itr = nums.begin() + 1; itr != nums.end(); ++itr){
            inc = max(*itr, inc + *itr);
            maxSum = max(inc, maxSum);
        }
        return maxSum;
    }
};
