class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string cmp = strs[0];
        for (auto &s : strs) cmp = match(cmp, s);
        return cmp;
    }

    string match(const string & cmp, const string & s){
        int index = 0, minLen = min(cmp.length(), s.length());
        for (; index < minLen; ++index){
            if (cmp[index] != s[index]) break;
        }
        return cmp.substr(0, index); // now new prefix is upto the index
    }
};
