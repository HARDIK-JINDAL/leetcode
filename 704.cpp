/* Leetcode 704 - Binary Search */

#include <iostream>
#include <vector>
using namespace std;

/*
Approach (Iterative Binary Search):
1. We initialize two pointers: st = 0 (start of array), end = nums.size() - 1 (end of array).
2. We enter a loop that continues as long as st <= end.
3. In each iteration:
   - We calculate the mid index using (st + end) / 2.
   - If nums[mid] is the target, we return mid.
   - If target > nums[mid], it means target lies in the right half, so we move st to mid + 1.
   - Else, the target lies in the left half, so we move end to mid - 1.
4. If we exit the loop, the element was not found, so we return -1.

Time Complexity: O(log n) — standard binary search on sorted array.
Space Complexity: O(1) — no extra space used.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int st = 0;                         
        int end = nums.size() - 1;          
        
        while (st <= end) {                 
            int mid = (st + end) / 2;       
            
            if (nums[mid] == target) {      
                return mid;
            }
            
            if (target > nums[mid]) {       
                st = mid + 1;
            } else {                        
                end = mid - 1;
            }
        }
        
        return -1;                          
    }
};
