class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> output;
        if (!numRows) return output;

        // First row
        output.push_back(vector<int> {1});
        // Creating each row
        for (auto i = 1; i < numRows; ++i){
            vector<int> row;
            // Each row elements
            for (auto j = 0; j <= i; ++j){
                // first and last element = 1
                if (j == 0 || j == i ) row.push_back(1);
                else {
                    // Elements in between
                    // if j -> add (output[i-1][j-1][j])
                    row.push_back(output[i-1][j-1] + output[i-1][j]);
                }
            }
            output.push_back(row);
        }

        return output;
    }
};
