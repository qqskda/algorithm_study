class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() < 2) return;
        // Using swaps per in range
        // It is to avoid overflow + unnecessary swaps
        k = k % nums.size();
        std::rotate(nums.rbegin(), nums.rbegin() + k, nums.rend());
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.size() < 2) return;
        k = k % nums.size();
        // Using Reverse = O(last-first / 2 swaps) = O(n/2)
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
