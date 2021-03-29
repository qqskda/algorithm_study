class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        // O(n)
        for (auto num : nums) map[num] ++;
        priority_queue<pair<int, int>> pq;
        // pair = [num, reps]
        for (auto& pair : map) pq.emplace(pair.second, pair.first);

        vector<int> output;
        while (k){
            k--;
            // pq.top() = [reps, num]
            output.push_back(pq.top().second);
            pq.pop();
        }
        return output;
    }
};

/*
k most frequent elements with time complexity better than O(n lg n).

Due to the time complexity limit -> sorting is not availble (except bucket sort).
1. Use hash to find distinct number of elements with its repetition -> O(n) with m distinct elements
2. Use priority_queue to construct ordered heap (Insert, delete, construct - O(lg n))

# push vs emplace
pq.push(pair(a, b)) -> make pair, copy (a,b) to the pair object, and append it to pq
pq.emplace(a,b) -> Directly construct pair(a,b) at the location - Skip unnecessary copy, append

so if available, use emplace rather than push
*/
