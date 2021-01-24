class Solution {
public:
    string addBinary(string a, string b) {
        // check the length
        if (a.length() == 0 || a == "0") return b;
        else if (b.length() == 0 || b == "0") return a;

        // return string
        string ret = "";

        // Will be used bothe as the sum and carry bit
        int currentBit = 0;

        // while both are not empty
        auto itrA = a.rbegin(); auto itrB = b.rbegin();
        while (itrA != a.rend() || itrB != b.rend() || currentBit != 0){
            if (itrA != a.rend()){
                currentBit += (*itrA == '0') ? 0: 1;
                ++itrA;
            }

            if (itrB != b.rend()){
                currentBit += (*itrB == '0') ? 0: 1;
                ++itrB;
            }

            // It is because currentBit is always less than 3
            ret = (currentBit % 2 == 0 ? '0' : '1') + ret;
            currentBit /= 2;
        }

        return ret;
    }
};
