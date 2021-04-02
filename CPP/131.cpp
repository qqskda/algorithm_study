class Solution {
public:

    bool isPalindrome(const string& a, int st, int ed){
        for (int start = st, end = ed-1; start < end; ++start, --end){
            if (a[start] != a[end]) return false;
        }
        return true;
    }

    void backtracking(string& s, int start, vector<string>& ss, vector<vector<string>>& res){
        if (s.size() == start){
            // if checked all the substrings -> append it to the result vec
            res.push_back(ss);
            return;
        }
        // else
        // increaing substring length from 1 to ~ for aab:  a a b -> aa b
        for (int end = start+1; end <= s.size(); ++end){
            //[start, end) -> check end at the above if statement
            if (isPalindrome(s, start, end)){
                // if s is palindrome within the range (substring)
                ss.push_back(s.substr(start,end-start));
                //cout << s << " " <<  ss.back() << endl;
                // shift the start to end
                backtracking(s, end, ss, res);
                // remove the substr after append it
                ss.pop_back();
            }

        }
    }

    vector<vector<string>> partition(string s) {
       vector<vector<string>> res;
        vector<string> ss;
        backtracking(s, 0, ss, res);
        return res;
    }
};

/*
Get all the palindrome: Once find a palindrome, its substring excluding start and end -> palindrome as well.
s.substr(begin, end);
s.substr(begin) -> till the end;
*/
