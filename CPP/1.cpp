class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // If there is only one valid answer, and two numbers;
        // Target - currentNum = needNum -> Check if I have needNum
        // Since we have to scan if the num exsits every loop -> choose map to have O(lg n)
        map<int, int> table;

        for (int index = 0; index < nums.size(); ++index){
            int needNum = target - nums[index];
            if (table.find(needNum) != table.end()){
                if (table[needNum] != index){
                    cout << needNum << nums[index] << endl;
                    return {table[needNum], index};
                }
            }
            table[nums[index]] = index;
        }
        return {0,0};
    }
};
// Implementation: To avoid returning the same two indices, Compare value with
// ONly what is in the table (previously checked numbers)
// That is why in Line 14: index is the second.
