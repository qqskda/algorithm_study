class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        // string is the key for the set<string> that starts/ends the same
        unordered_map<string, set<string>> first, second;
        // Used ordered set to ease the push_back for the output vector.
        // And to avoid duplicates
        // It contains the merged strings
        set<string> res;
        for (auto phrase : phrases){
            // Find the position of each first and second word in the phrase
            auto firstPos = phrase.find(' '); auto secondPos = phrase.rfind(' ');

            // Check the found position - npos represents No Position found
            // fistPos not found -> only one word
            firstPos = (firstPos == string::npos) ? phrase.size() : firstPos;
            // secondPos not found -> only one word, found -> +1 is the start of the word
            secondPos = (secondPos == string::npos) ? 0 : secondPos + 1;

            // Eg. I am Fine
            // firstPos = blank after I. secondPos = F of fine.

            // Remember each phrase can be used either first or the second phrase.
            // if a phrase not found -> will be simply skipped
            // find a phrase that starts with phrase's last word
            for (auto pPhrase : first[phrase.substr(secondPos)]) res.insert(phrase + pPhrase);
            // find a phrase that ends with phrase's first word
            for (auto pPhrase : second[phrase.substr(0, firstPos)]) res.insert(pPhrase + phrase);


            // key = firstWord, Value = first to the end
            first[phrase.substr(0,firstPos)].insert(phrase.substr(firstPos));
            // key = lastWord, value = first to the word before the end
            // It is to aovid the duplicates
            second[phrase.substr(secondPos)].insert(phrase.substr(0, secondPos));
        }

        // return by type casting
        return vector<string>(res.begin(), res.end());
    }
};
