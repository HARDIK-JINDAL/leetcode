/* Leetcode 217 - Contains Duplicate */

#include <vector>
#include <algorithm>  
using namespace std;

/*
Approach (Sorting + Adjacent Comparison):
-----------------------------------------
1. We are given an integer array and asked to return true if any value appears at least twice.
2. Since duplicate values will be adjacent after sorting, we sort the array first.
3. Then, we iterate through the sorted array and compare each element with its next neighbor:
   - If nums[i] == nums[i + 1], we return true (duplicate found).
4. If we finish the loop without finding duplicates, we return false.

Time Complexity: O(n log n) → due to sorting step
Space Complexity: O(1) → assuming in-place sort (like std::sort)
*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        for(int i = 0 ; i < nums.size()-1 ; i++){
            if(nums[i]==nums[i+1]){
                return true;
            }
        }
        return false;
    }

};