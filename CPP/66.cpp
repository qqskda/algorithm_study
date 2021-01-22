class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for (auto itr = digits.rbegin(); itr != digits.rend(); ++itr){
            if (*itr != 9){
                *itr += 1;
                return digits;
            } else {
                *itr = 0;
            }
        }
        // If the digits length will not be changed, the above loop covers all.
        // In this increment, there will be no case where the carry bit becomes 2,
        // but only one.
        // Therefore, if the digits dont get reutrned in the above loop,
        // all we have to do is just insert the most significant bit.
        digits.insert(digits.begin(), 1);
        return digits;
    }
};
