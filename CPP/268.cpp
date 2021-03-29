class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // Gauss Method
        int expSum = 0, actSum = 0;
        for (int i = 1; i <= nums.size(); ++i){
            actSum += nums[i-1];
            expSum += i;
        }

        // expSum is always larger as there is a missing number in the given list.
        return expSum - actSum;
    }

    int missingNumber(vector<int>& nums) {
    // XOR Method
    int missing = 0;

    // Add expected nums to missing
    for (int i = 1; i <= nums.size(); ++i) missing ^= i;

    // Subtract element of nums from missing
    for (int num : nums) missing ^= num;

    return missing;
    }
};

/*
There could be many ways to solve this.
1. Set (hash)
2. Sorting
3. XOR
4. Gauss
*/
