class Solution {
public:
    int calc(int n){
        int a = 1;
        int ret = 0;
        while (n){
           ret += a;
           a++; n--;
        }
        return ret;
    }
    int countLetters(string S) {
        if (S.size() == 1) return 1;

        int sub_count = 0;
        char prev = S[0]; int prev_count = 1;
        for (int i = 1; i < S.size(); ++i){
            char curr = S[i];
            if (prev != curr){
                // Add up the prev char counting
                sub_count += calc(prev_count);
                prev = curr;
                prev_count = 1;
            } else{
                prev_count++;
            }

        }

        sub_count += calc(prev_count);

        return sub_count;
    }
};

/*
returns count -> find mathematical formula
n = 3 -> 3 + length2 * 2 + length 3
aaa -> a, a, a, aa aa, aaa
n = 4 -> 4 + length2 * 3 + length 3 * 2 + length4 * 1
aaaa -> a,a,a,a aa aa aa, aaa aaa aaaa

for consecutive n -> 1 (n), 2 (n-1), 3(n-2), 4 (n-3)...
*/
