class Solution {
public:
    bool isPalindrome(int x) {
        string rev = to_string(x);
        reverse(rev.begin(), rev.end());
        return (rev == to_string(x)) ? true : false;
    }
};

// OR typical reverse number method is available as well.
