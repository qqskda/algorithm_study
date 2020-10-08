// https://en.wikipedia.org/wiki/Maximum_subarray_problem

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size(), res = nums[0], left= 0, right = 0;
        for (int i = 0; i < n; i++){
            // If there cannot be zero in an array, it can be one big n scan
            // Since there can be zero, we can divide it into subproblems; reset when there is zero
            left = (left ? left : 1) * nums[i];
            right = (right ? right : 1) * nums[n - i - 1];
            // Compare res, left, right while reset left and right to 1 whenever encounter 0
            res = max(res, max(left, right));
        }
        return res;
    }
};