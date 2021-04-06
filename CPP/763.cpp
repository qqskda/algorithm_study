class Solution {
public:
    vector<int> partitionLabels(string S) {
        // Record the highest index for each letter
        unordered_map<int, int> mp;
        for (int i = 0; i < S.size(); ++i){
            mp[S[i]] = i;
        }

        // while append a list (partial) update its max index
        vector<int> vec;

        for (int i = 0, maxIndex = 0, count = 0; i < S.size(); ++i){
            // if not passed the index yet
            maxIndex = max(maxIndex, mp[S[i]]);
            count++;
            // if passed the index
            if (i >= maxIndex){
                vec.push_back(count);
                count = 0;
                maxIndex = 0;
                continue;
            }
        }

        return vec;
    }
};

/*
Each letter appears in at most one part -> a letter can only exist at one list.
Split the string once all used letters are appended.
-> Keep in track of how many letter exist/have and its index.
*/
