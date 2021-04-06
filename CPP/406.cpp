class Solution {
public:
    static bool cmp (const vector<int>&a, const vector<int>&b){
        // sort by ascending if the value is same
        if (a[0] == b[0]) return a[1] < b[1];
        // sort by descending for value
        else return a[0] > b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);

        int sz = people.size();
        // No need to define size as it will insert in the beginning.
        vector<vector<int>> vec;
        for (auto person : people){
            // vec is in descending order by value
            // ascending by its second.
            // By insert bigger value first -> vec becomes in ascending order eventually
            vec.insert(vec.begin() + person[1], person);
        }
        return vec;
    }
};
