/* Leetcode 540 - Single Element in a Sorted Array (Binary Search)*/

#include <iostream>
#include <vector>
using namespace std;

/*
Approach (Binary Search on Index Pattern):
1. We are given a sorted array where every element appears exactly twice except for one element that appears once.
2. In such arrays, pairs start at even indices and their duplicates are at the next odd index (i.e., index 0 == 1, 2 == 3, etc.) until the single element.
3. We perform binary search with two pointers: st = 0, end = nums.size() - 1.
4. In each iteration:
   - We calculate mid = (st + end) / 2.
   - If nums[mid] is the unique element (not equal to neighbors), we return it.
   - Else, we use the pairing index pattern:
     - If mid is even:
       - If nums[mid] == nums[mid + 1], the unique element is on the right → move st = mid + 2.
       - Else, it's on the left → move end = mid.
     - If mid is odd:
       - If nums[mid] == nums[mid - 1], the unique is on the right → move st = mid + 1.
       - Else, it's on the left → move end = mid - 1.
5. Loop continues until st > end. If we exit loop, return 0 (though that shouldn’t happen on valid input).

Time Complexity: O(log n) — efficient binary search.
Space Complexity: O(1) — constant space.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int st = 0;                         
        int end = nums.size() - 1;          

        while (st <= end) {
            int mid = (st + end) / 2;       

            // Edge case: Only one element in array
            if (end + 1 == 1) return nums[end];

            // Check if mid is the single element
            if ((mid == 0 && nums[mid] != nums[1]) || 
                (mid == nums.size() - 1 && nums[mid] != nums[mid - 1]) || 
                (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])) {
                return nums[mid];
            }

            // Binary search logic based on pair positioning
            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid - 1]) {
                    end = mid - 1;
                } else {
                    st = mid + 1;
                }
            } else {
                if (nums[mid] == nums[mid - 1]) {
                    st = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
        }

        return 0;  // Not expected in valid input
    }
};


/*
Approach (Linear Scan):
1. Traverse the array from index 0 to n-1 in steps of 2 (since elements are in pairs).
2. At each step, compare nums[i] with nums[i+1]:
   - If they are equal, continue to the next pair.
   - If they are not equal, then nums[i] is the single non-duplicate element.
3. If the loop finishes and no mismatch is found, the last element is the single one.

Time Complexity: O(n) — in worst case, we check all elements.
Space Complexity: O(1) — no extra space used.
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i += 2) {
            if (nums[i] != nums[i + 1]) {
                return nums[i];  // Found the single non-duplicate
            }
        }
        return nums.back();  // Last element is the single one
    }
};
