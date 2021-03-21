class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // std::set is typically implemented as a binary search tree(RB tree in GCC 4.8).
        // It costs O(nlogn) to construct. While std::unordered_set uses hash table, O(n) is expected.

        return nums.size() > set<int>(nums.begin(), nums.end()).size();
    }
};
