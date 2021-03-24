class NumArray {
public:
    NumArray(vector<int>& nums) {
        dp.push_back(0);
        for (auto num : nums){
            dp.push_back(dp.back() + num);
        }
    }

    int sumRange(int left, int right) {
        // nums = [1,2,3] -> dp = [0,1,3,6]
        // sumRange(0,2) -> dp[2+1] - dp[0] = 6
        return dp[right+1] - dp[left];
    }
private:
    vector<int> dp;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
