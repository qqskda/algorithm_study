class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insIndex = 0, zeroCount = 0, sz = nums.size();
        
        for (int scanIndex = 0; scanIndex < sz; ++scanIndex){

            if (sz > insIndex + zeroCount){
                // cout << scanIndex << " " << insIndex << " " << zeroCount << endl;
                if (nums[scanIndex] != 0){
                    nums[insIndex] = nums[scanIndex];
                    insIndex++;
                } else {
                    // insIndex remains the same
                    zeroCount++;
                }
            }
        }
        
        for (; insIndex < nums.size(); ++insIndex){
            nums[insIndex] = 0;
        }
        
    }
};

/*
Need count of zeros, when nums.size() > insIndex + zeroCount -> fill rest 0
Need a insertIndex, scanIndex
*/