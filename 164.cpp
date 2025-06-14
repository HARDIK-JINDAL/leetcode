/*Leetcode 164 - Maximum Gap

Approach:
1. Sort the array `nums` in ascending order.
2. Traverse the sorted array and compute the difference between every pair of adjacent elements.
3. Keep track of the maximum difference encountered during this traversal.
4. Return this maximum difference.

Dry Run:
Input: nums = [3, 6, 9, 1]
After sorting: [1, 3, 6, 9]
- gap1 = 3 - 1 = 2
- gap2 = 6 - 3 = 3
- gap3 = 9 - 6 = 3
Maximum Gap = 3

Time Complexity: O(n log n) → due to sorting
Space Complexity: O(1) → if sort is in-place
*/

#include <vector>
#include <algorithm>  // for sort()
using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int diff = 0 ;
        for(int i = 0 ; i<nums.size()-1;i++){
            diff=max(diff,(nums[i+1]-nums[i]));
        }
        return diff;
        
    }
};