class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // if cannot find any element -> target is the biggest
        int index = nums.size();
        for (int i = 0; i < nums.size(); ++i){
            if (!(nums[i] < target)){
                // insert target is not bigger than the array element
                index = i;
                break;
            }
        }
        return index;
    }
};


// log N
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int index = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        return index;
    }
};
