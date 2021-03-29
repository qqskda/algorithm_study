class Solution {
public:
    int titleToNumber(string columnTitle) {
        long int ret = 0, temp = 0;
        for (auto itr = columnTitle.begin(); itr != columnTitle.end(); ++itr){
            temp = *itr - 'A' + 1;
            // cout << temp << endl;
            ret *= 26;
            ret += temp;
        }
        return ret;
    }
};  
