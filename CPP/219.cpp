class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Find duplicates that are in distance <= k
        unordered_map<int, vector<int>> mp;

        // Append map with its index;
        for (int i = 0; i < nums.size(); ++i){
            mp[nums[i]].push_back(i);
        }

        for (auto elem : mp){
            // if it is not duplicated, dont bother
            if (elem.second.size() < 1) continue;
            int base = elem.second[0];
            for (int i = 1; i < elem.second.size(); ++i){
                if ((elem.second[i] - base) <= k) return true;
                else base = elem.second[i];
            }
        }

        return false;

    }
};

// Live Tracking
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int sz = nums.size();

        for (int i =0; i < sz; ++i){
            if (!mp.count(nums[i])) mp[nums[i]] = i;
            else {
                // if it already exists -> duplicate
                if ((i - mp[nums[i]]) <= k) return true;
                // if diff is big -> update indexx
                else mp[nums[i]] = i;
            }
        }
        return false;
    }
};
