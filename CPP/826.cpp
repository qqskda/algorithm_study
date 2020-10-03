class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> concVec;
        int d_size = difficulty.size();
        
        // Pair two one-dimensional vector into one two-dimensional vector
        for (int i = 0; i < d_size; ++i) concVec.push_back(make_pair(difficulty[i], profit[i]));
        
        // Sorting
        sort(concVec.begin(), concVec.end());
        sort(worker.begin(), worker.end());
        
        int sums = 0, most = 0, d_index = 0;
        for (int i = 0; i < worker.size(); ++i){
            while (d_index < d_size && worker[i] >= concVec[d_index].first){
                most = max(most, concVec[d_index].second);
                d_index++;
            }
            sums += most;
        }
        return sums;
    }
};