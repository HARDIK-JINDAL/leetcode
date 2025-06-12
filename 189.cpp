/*Leetcode 189 - Rotate Array*/

#include <iostream>
#include <vector>
using namespace std;

/*
Approach:
1. Create a temporary array `temp` of the same size as `nums`.
2. Traverse each element in `nums`. For every index `i`, place `nums[i]` at index `(i + k) % nums.size()` in `temp`.
3. Copy all elements from `temp` back to `nums`.

Dry Run:
Input: nums = [1, 2, 3, 4, 5, 6, 7], k = 3
Step-by-step:
- i = 0 → temp[(0 + 3) % 7] = temp[3] = 1
- i = 1 → temp[4] = 2
- i = 2 → temp[5] = 3
- i = 3 → temp[6] = 4
- i = 4 → temp[0] = 5
- i = 5 → temp[1] = 6
- i = 6 → temp[2] = 7
Final temp = [5, 6, 7, 1, 2, 3, 4] → Copy back to nums

Time Complexity: O(n)
Space Complexity: O(n)
*/

#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());  // Step 1: Create temp array

        for (int i = 0; i < nums.size(); i++) {
            temp[(i + k) % nums.size()] = nums[i];  // Step 2: Place at new rotated index
        }

        nums = temp;  // Step 3: Copy temp back to nums
    }
};
