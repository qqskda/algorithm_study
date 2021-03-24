class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), intersect = 0;
        int t_size = 0;
        for (char ch : s){
            while(t_size < t.size()){
                if (ch == t[t_size]){
                    intersect++;
                    t_size++;
                    break;
                }
                t_size++;
            }
        }
        if (intersect != n) return false; else return true;
    }
};
