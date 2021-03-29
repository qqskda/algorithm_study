class Solution {
public:
    vector<vector<int>> ret;
    vector<vector<int>> subsets(vector<int>& nums) {
        // BackTracking
        vector<int> temp;
        backtrack(nums, temp, 0);
        return ret;
    }

    void backtrack(vector<int>& nums, vector<int> temp, int index){
        if (index == nums.size()) {
            ret.push_back(temp);
            return;
        }
        // without current index num
        backtrack(nums, temp, index+1);
        // add current index num
        temp.push_back(nums[index]);
        // with current index num
        backtrack(nums, temp, index+1);
    }
};

/*
It is not permustaions, but subsets.
1. Cascading
[]
1
2
1 2
3
1 3
2 3
1 2 3

2. Backtracking
1
1 2
1 2 3
1 3
2
2 3
3
*/
