class Solution {
public:
    bool isValid(string s) {
        // Stack will be the best choince
        // } and ) must match the stack top.
        vector<char> stk;
        for (char ch : s){
            cout << ch << " ";
            if (ch == '(' | ch == '{' | ch == '['){
                stk.push_back(ch);
            } else {
                if (stk.empty()) return false;
                if (ch == ']' & stk.back() == '[') stk.pop_back();
                else if (ch == ')' & stk.back() == '(') stk.pop_back();
                else if (ch == '}' & stk.back() == '{') stk.pop_back();
                else return false;
            }
        }
        cout << endl;
        return (stk.empty()) ? true:false;
    }
};
