class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;
        int sigh = nums.size();
        for (int i = 0; i < nums.size(); ++i){
            if (hashTable.count(target - nums[i])){
                // i is the current index
                // first is the previously recorded ones
                // this method allows to avoid access same element twice
                 return {hashTable[target - nums[i]], i};
            }
            hashTable[nums[i]] = i; // if the needNum is not in the hash -> first index
        }
        return {sigh, sigh};
    }
};
