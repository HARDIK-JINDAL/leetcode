// Leetcode 33 - Search in Rotated Sorted Array

#include <iostream>
#include <vector>
using namespace std;

/*Approach 1: Binary Search in Rotated Sorted Array
1. Initialize start and end pointers for binary search.
2. Calculate the mid index each time.
3. Check if nums[mid] == target => return mid.
4. Determine if left half [st to mid] is sorted:
   - If yes, check if target lies within this half => shrink end.
   - Else, search in right half => shift start.
5. If right half [mid to end] is sorted:
   - Check if target lies in that half => move start.
   - Else, shrink end to mid - 1.
6. Repeat until start > end. If not found, return -1.
Time Complexity: O(log n) - binary search.
Space Complexity: O(1) - constant space.*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int end = nums.size() - 1;
        int st = 0;

        while (st <= end) {
            int mid = (st + end) / 2;

            // Case 1: Found target
            if (nums[mid] == target) {
                return mid;
            }

            // Case 2: Left half is sorted
            if (nums[st] <= nums[mid]) {
                if (nums[st] <= target && target <= nums[mid]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            }

            // Case 3: Right half is sorted
            else {
                if (nums[mid] <= target && target <= nums[end]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return -1; // Target not found
    }
};

/*Approach 2: Brute Force (Linear Search)
 1. Iterate through each element of the array.
 2. Check if the current element equals the target.
 3. If found, return the index.
 4. If not found after the loop ends, return -1.

 Time Complexity: O(n) - must check every element.
Space Complexity: O(1) - no extra space used.*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1;
    }
};
