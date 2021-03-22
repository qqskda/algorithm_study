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

class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int vecSize = nums.size();
        // two pointer - find non-zero and insert it in slow pos.
        size_t slow = 0, fast = 0;
        for (; fast < vecSize; ++fast){
            if (nums[fast] != 0){
                nums[slow] = nums[fast];
                ++slow;
            }
        }
        // slow -> starts of zeros
        for (; slow < vecSize; ++slow){
            nums[slow] = 0;
        }


    }
};
