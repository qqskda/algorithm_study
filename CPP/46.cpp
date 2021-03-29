class Solution {
public:
    vector<vector<int>> output;

    vector<vector<int>> permute(vector<int>& nums) {
        backTrack(0, nums);
        return output;
    }

    void backTrack(int index, vector<int>& nums){
        if (index == nums.size()) {
            // printer(nums);
            output.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); ++i){
            // Make a move
            swap(nums[index], nums[i]);
            // Try
            backTrack(index+1, nums);
            // Recall the move
            swap(nums[index], nums[i]);
        }
    }

    // void printer(vector<int>& nums){
    //     for (int num : nums){
    //         cout << num <<" ";
    //     }
    //     cout << endl;
    // }
};

/*
Permutations - Try all the possible permutations - backtracking.

Set first digit -> possible second digit -> possible third digit ....

How to avoid/know ones that are already covered?
Swap the element -> each iteration of the function will be unique

num = 1
1 2 3 4
1 2 3 4 push
1 2 4 3 push
1 2 3 4
1 3 2 4 push
1 3 4 2 push
1 2 3 4
1 4 3 2 push
1 4 2 3 push
1 2 3 4
2 1 3 4 push
2 1 4 3 push
2 1 3 4
2 3 1 4 push
2 3 4 1 push
2 1 3 4
2 4 1 3 push
...
*/
