class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 0, movItr = 1;

        if (nums.size() == 0) return 0;

        for (; movItr < nums.size(); ++movItr){
            if (nums[index] != nums[movItr]){
                // Found the new elements
                index++; // Mov the element next to the previous unique number
                nums[index] = nums[movItr];
            } // if
        } // for loop

        // Seems like we do not have to resize the vector
        // It only cares whether we found the answer by modifying the vector
        return index + 1;
    }
};
