class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() < 2) return {{strs}};

        unordered_map<string, vector<string>> mp;

        for (auto str : strs){
            mp[sorter(str)].push_back(str);
        }
        vector<vector<string>> ret;

        for (auto p : mp){
            ret.push_back(p.second);
        }

        return ret;
    }

    string sorter(string str){
        int counting[26] = {0};
        for (char ch : str){
           counting[ch-'a'] ++;
        }

        string ret;
        for (int ch = 0; ch < 26; ++ch){
            // Append ch+'a' char counting[ch] times.
            ret += string(counting[ch], ch+'a');
        }
        return ret;
    }
};

/*
Anagram: consists of same alphabets with same repetitions.
Compare:
1. Key: Sorted words, values: list of anagrams
2. Unordered_map, counting sort (as there are only 27 chars)
*/class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() < 2) return {{strs}};

        unordered_map<string, vector<string>> mp;

        for (auto str : strs){
            mp[sorter(str)].push_back(str);
        }
        vector<vector<string>> ret;

        for (auto p : mp){
            ret.push_back(p.second);
        }

        return ret;
    }

    string sorter(string str){
        int counting[26] = {0};
        for (char ch : str){
           counting[ch-'a'] ++;
        }

        string ret;
        for (int ch = 0; ch < 26; ++ch){
            // Append ch+'a' char counting[ch] times.
            ret += string(counting[ch], ch+'a');
        }
        return ret;
    }
};

/*
Anagram: consists of same alphabets with same repetitions.
Compare:
1. Key: Sorted words, values: list of anagrams
2. Unordered_map, counting sort (as there are only 26 chars)
*/
