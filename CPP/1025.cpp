class Solution {
public:
    bool divisorGame(int N) {

        if (N == 1) return false;

        vector<bool> dp(N+1, false);

        // Filing out all possibilites
        for (int i = 2; i <= N; ++i){
            for (int j = 1; j * j <= i; ++j){
                // it is j*j because we need value that is i % j == 0
                // May think 2*j but result is the same. ig. i = 9, j = 4.5 or 3 -> 3 is better
                // ig i = 15, j = 3,5,15 -> 3 is better
                if (i % j == 0 && !dp[i-j]) dp[i] = true;
            }
        }
        return dp[N];

    }
};
/*
Approach like fibonacci -> save the result when N is small
When I am in A position, if A-B position is true -> A is ultimately a losing position.
*/
