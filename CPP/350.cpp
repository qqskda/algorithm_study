class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // bruteforce to compare each will be O(n^k) where k < n
        // 2 Sorts = O(n lg n)
        // set_intersection = O(2 * (n-k) - 1) = O(n)
        // Given input parameter is not const -> modify to save space
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        // Find intersection of nums1 and nums2 from the beginning and end
        // Then erase
        nums1.erase(set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), nums1.begin()), nums1.end());

        return nums1;
    }
};
