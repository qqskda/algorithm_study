class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int tortoise = nums[0], hare = nums[0];

        while (true){
            // Set Two diff speed travellers.
            tortoise = nums[tortoise];
            hare = nums[nums[hare]];
            if (tortoise == hare) break;
        }
        // Now find the cycle entrance
        // Reset the slow traveller
        tortoise = nums[0];
        while (tortoise != hare){
            // Now both travel in the same speed (slow)
            tortoise = nums[tortoise];
            hare = nums[hare];
        }

        return hare;
    }
};

/*
Given Info:
1. Integer is in the range [1,n]
2. Nums containing n+1 integers
3. There is only one repeated number in nums

1 3 4 2 2
0 1 2 3 4
3 2 2 4 4

-> There is a cycle when you travel by taking value of nums[index] as another index for next step.
-> Floyd's Tortoise and Hare (Cycle Detection Algorithm)
Different Starting point -> break when it intersects.

Tortoise: Slow ptr, Hare: Fast ptr
Tortoise = starts with nums[0]
Hare = starts with nums[nums[0]]

Once Found the intersection -> need to find where it started
Tortoise and Hare now travels with in the same speed.
Tortoise starts from the beginning
Hare is travelling within the cycle.
when Tortoise == Hare -> Cycle Entrance

Another Implementation:
Typical Set, or sort will do
*/
