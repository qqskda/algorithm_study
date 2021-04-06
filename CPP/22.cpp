class Solution {
public:

    vector<string> vec;
    void generate(string curr, int open, int close, const int& n){
        if (curr.size() == 2*n){
            vec.push_back(curr);
            return;
        }

        if (open < n)
            generate(curr + "(", open+1, close, n);
        if (close < n && close < open)
            generate(curr + ")", open, close + 1, n);

    }

    vector<string> generateParenthesis(int n) {
        generate("", 0, 0, n);
        return vec;
    }
};

/*
Backtracking question -> try all the combination,  append if it is valid
How to validate the parentheses:
open ( count  == close ) count
How to generate various parentheses:
1. make n open
2. append
3. close and make rest parentheses
if n == 3
1. ((()))
2. (()())
3. (())()
4. ()(())
5. ()()()
*/
