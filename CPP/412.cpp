class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> vec;

        for (int i = 1; i <= n; ++i){
            vec.push_back(getStr(i));
        }
        return vec;
    }

    string getStr(int n){
        string ret;
        if (n % 3 == 0) ret = "Fizz";
        else if (n % 5 == 0) ret = "Buzz";
        else ret = to_string(n);

        if (n % 3 == 0 && n % 5 == 0) ret = "FizzBuzz";

        return ret;
    }
};
