/* Leetcode 724 - Find Pivot Index (Brute Force Approach)

Approach:
1. We are given an array `nums` and need to find the **pivot index**.
2. A pivot index is where the **sum of elements on the left == sum of elements on the right**.
3. For each index `i`, we calculate:
   - Left sum: sum of all elements before index `i`
   - Right sum: sum of all elements after index `i`
4. If both sums are equal, return the index as the pivot index.
5. If no such index exists, return -1.

Time Complexity: O(n^2)
- For every index, we compute left and right sums (linear operations inside a loop).
Space Complexity: O(1)
- We use constant extra space (just a few int variables).
*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); i++) {
            int ls = 0; // left sum
            int rs = 0; // right sum
            for (int j = i + 1; j < nums.size(); j++) {
                rs += nums[j];
            }
            for (int k = 0; k < i; k++) {
                ls += nums[k];
            }
            if (ls == rs) {
                return i;
            }
        }
        return -1;
    }
};
