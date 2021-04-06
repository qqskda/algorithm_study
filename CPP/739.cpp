class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if (T.empty()) return T;

        stack<pair<int,int>> stk;
        stk.push(make_pair(T.back(), 0));

        int sz = T.size();
        vector<int> vec(sz, 0);

        for (int i = sz-1; i >= 0; --i){
            int counter = 1;

            while(!stk.empty() && stk.top().first <= T[i]){
                // curr is bigger than top -> top is useless
                counter += stk.top().second;
                stk.pop();
            }

            if (stk.empty()) stk.push(make_pair(T[i], 0));
            else {
                stk.push(make_pair(T[i], counter));
                vec[i] = counter;
            }
        }

        return vec;
    }
};

/*
Waiting warmer temp -> last one has 0 waiting days
Read the vector reversely -> using queue;
When to remove the queue:
 Once lower index is warmer than higher indices -> pop all cooler days

*/
