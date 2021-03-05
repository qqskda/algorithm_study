class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int theNum = 0, theCnt = 1;

        for (auto num : nums){
            if (num == theNum) theCnt++;
            else if (theCnt == 1){
                theNum = num;
                theCnt = 1;
            } else {
                theCnt--;
            }
        }
        return theNum;
    }
};
