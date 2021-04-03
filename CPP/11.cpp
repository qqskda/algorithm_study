class Solution {
public:
    int maxArea(vector<int>& height) {
        int first = 0, last = height.size()-1;
        int soFarMax = 0;
        while (first < last){
            int left = height[first], right = height[last];
            soFarMax = max(min(left, right) * (last-first), soFarMax);

            if (left > right){
                // if left bar is higher -> change right one
                last--;
            } else first++;
        }
        return soFarMax;
    }
};

/*
Most Water = (index diff) * (min(indices height))
From first and last -> shriking the box
How should we shrink to find the possible max?
if a < b; a is not contributing -> replace a to find bigger one
*/
