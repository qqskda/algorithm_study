class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Single number -> use bitwise.
        
        int output = 0;
        for (auto& num : nums){
            output ^= num;
        }
        return output;
    }
};