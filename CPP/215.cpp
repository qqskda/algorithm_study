class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int num : nums){
            pq.push(num);
        }
        for (int i = 0; i < nums.size() - k; ++i){
            pq.pop();
        }

        return pq.top();
    }
};


/*
kth largest element
1. search O(n) for n elements in nums
2. Data Structures pq -> O(n * lg  k) for k distinct elemtns in n.

Used min_pq
*/
