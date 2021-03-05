class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        if (nums.size() < 2) return;

        size_t slow = 0;

        for (size_t index = 0; index < nums.size(); ++index){
            if (nums[slow] == 0 && nums[index] != 0){
                // Swap happening
                swap(nums[slow], nums[index]);
            }

            if (nums[slow] != 0) slow++;
        }
    }
};
