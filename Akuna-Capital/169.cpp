class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int threshold = nums.size() / 2;
        
        unordered_map<int, int> mp;
        
        // It is guaranteed to return if there is a majority element.
        for (auto& num : nums){
            mp[num]++;
            if (mp[num] > threshold) return num;
        }
        
        // If there is no majority element
        return -1;
    }
};