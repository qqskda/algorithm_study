class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.size()  == 0) return 0;
        int index = 0;
        for (int itr = 0; itr < nums.size(); ++itr){
            // Not the element -> replace the index element
            if(nums[itr] != val){
                nums[index] = nums[itr];
                index++;
            }
        }
        return index;
    }
};
