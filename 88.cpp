/* Leetcode 88 - Merge Sorted Array (Two Pointers - In-place) */

#include <iostream>
#include <vector>
using namespace std;

/*
Approach (Merge from End using Two Pointers):
1. We're given two sorted arrays: 
   - nums1 of size m+n (with m elements filled and n zeroes at the end)
   - nums2 of size n.
2. Our task is to merge nums2 into nums1, and sort the merged array in-place.
3. Since both arrays are sorted, we'll use a Two Pointer Technique starting from the end:
   - Pointer i at end of nums1's actual elements (m-1)
   - Pointer j at end of nums2 (n-1)
   - Pointer k at end of total nums1 space (m+n-1)
4. We compare nums1[i] and nums2[j] and insert the larger one at nums1[k].
5. We keep moving backward and placing elements at the right place.
6. If nums2 has elements left over, we copy them.
    (No need to copy nums1 leftovers, they're already in place.)
Time Complexity: O(m + n)
Space Complexity: O(1)
        */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m - 1;          // Pointer at end of nums1's actual elements
        int j = n - 1;          // Pointer at end of nums2
        int k = m + n - 1;      // Pointer at end of nums1 (total size)

        // Step 1: Merge from the back while both pointers are in bounds
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // Step 2: If nums2 has leftover elements, copy them
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }

    }
};
