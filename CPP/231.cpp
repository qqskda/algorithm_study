class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 ? !(n & n-1) : false;
    }
};

//  If n is power of 2 -> Use & bitwise between n and n-1; bitwise between odd and even.