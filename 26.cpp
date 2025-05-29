/* Leetcode 26 - Remove Duplicates from Sorted Array */

#include<iostream>
#include<vector>
using namespace std;

/*
Approach 1 (Optimized - Two Pointer Technique):
1. We are given a sorted array, so duplicates will always be next to each other.
2. Use two pointers — `i` for placing unique elements, `j` for scanning.
3. Start with `i = 0`, assume first element is always unique.
4. Traverse the array with `j` starting from index 1.
5. If `nums[j]` is different from `nums[i]`, increment `i` and copy `nums[j]` to `nums[i]`.
6. At the end, `i + 1` will be the count of unique elements.

Time Complexity: O(n) — single pass through the array.
Space Complexity: O(1) — in-place, no extra space used.
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        int i = 0 ; 
        for(int j = 1 ; j < nums.size(); j++){
            if(nums[i] != nums[j]){
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};


/*
Approach 2 (Brute Force - Shifting Duplicates):
1. We are given a sorted array, so duplicates will always be next to each other.
2. We loop through the array and check if the current element is equal to the next one.
3. If it's a duplicate:
   - Shift all elements to the left starting from the duplicate index.
   - Pop the last element since it becomes redundant after shifting.
   - Decrement `i` to recheck the same index with the new value.
4. If it's not a duplicate, we simply increment the `count` which keeps track of unique elements.
5. We stop early if we find the array is no longer sorted (though for Leetcode, it's guaranteed sorted).
6. Finally, return `count` as the number of unique elements.

Time Complexity: O(n^2) — due to nested loop caused by shifting.
Space Complexity: O(1) — in-place manipulation.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 1; 

        for(int i = 0 ; i < nums.size() - 1 ; i++) {
            if(nums[i] > nums[i + 1]){
                break;
            }
            else if(nums[i] == nums[i + 1]){
                for(int j = i + 1 ; j < nums.size() - 1 ; j++){
                    nums[j] = nums[j + 1];
                }
                nums.pop_back();
                i--;
            }
            else{
                count++;
            }
        }

        return count;
    }
};
*/

