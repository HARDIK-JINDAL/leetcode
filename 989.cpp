/*
Leetcode 989 - Add to Array-Form of Integer

Approach:
1. Treat the vector `nums` as a number in array-form and add integer `k` to it from the least significant digit (end of the array).
2. Traverse from the back:
   - Add `k` to the current digit.
   - Update the digit to `nums[i] % 10`.
   - Carry forward the value of `k = nums[i] / 10`.
3. After the loop, if `k` still has digits (carry remains), insert each digit of `k` at the beginning of `nums`.

Dry Run:
Input: nums = [1, 2, 0, 0], k = 34
Step-by-step:
- i = 3: nums[3] = 0 + 34 = 34 → nums[3] = 4, k = 3
- i = 2: nums[2] = 0 + 3 = 3 → nums[2] = 3, k = 0
- No more carry, final nums = [1, 2, 3, 4]

Time Complexity: O(max(n, log k))
Space Complexity: O(1) if ignoring output space, else O(n)
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& nums, int k) { 
        for (int i = nums.size() - 1; i >= 0; i--) {
            nums[i] += k;             
            k = nums[i] / 10;         
            nums[i] = nums[i] % 10;   
        }
        while (k > 0) {
            nums.insert(nums.begin(), k % 10);
            k /= 10;
        }

        return nums;
    }
};
