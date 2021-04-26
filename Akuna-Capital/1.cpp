class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // O(N) for both space and time
        
        // {val, index}
        unordered_map<int, int> mp;
        
        // Scan once to avoid returning same indices. ig: 6 for two 3s

        for (int i = 0; i < nums.size(); ++i){
            int needNum = target - nums[i];
            if (mp.find(needNum) != mp.end()){
                // it exists
                return {i, mp[needNum]};
            }
            mp[nums[i]] = i;
        }
        return {0,0};
    }
};