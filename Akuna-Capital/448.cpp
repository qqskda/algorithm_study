class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // sort takes nlgn
        // space complexity O(n), time complexity O(2n)
        
        unordered_set<int> st;
        
        int n = nums.size();
        // O(n) for both time and space
        for (auto& num : nums){
            st.insert(num);
        }
        
        // range = 1,n
        vector<int> omits = {};
        
        // worst O(n)
        for (int expNum = 1; expNum <= n; ++expNum){
            // unordered_set search time O(1)
            if (st.find(expNum) == st.end()){
                omits.push_back(expNum);
            }
        }
        return omits;
    }
};


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // Since range is [1, n] where n = nums.size()
        // can mark each index of nums as of its visited number
        // Since we need number, mark it as negative
        
        for (int i = 0; i < nums.size(); ++i){
            // negate the number
            int newIndex = abs(nums[i]) - 1;
            if (nums[newIndex] > 0) nums[newIndex] *= -1;
        }
        
        vector<int> output;
        for (int i = 0; i < nums.size(); ++i){
            // if not negative, did not have the num
            if (nums[i] > 0) output.push_back(i+1);
        }
        return output;
    }
};