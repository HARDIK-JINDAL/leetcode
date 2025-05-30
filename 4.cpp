/* Leetcode 4 - Median of Two Sorted Arrays */

#include <iostream>
#include <vector>
using namespace std;

/*
Approach: Brute Force - Merge and Find Median

1. We are given two sorted arrays: nums1 and nums2.
2. We will merge both arrays into a single sorted array called `merge`.
3. Use two pointers `i` and `j` to iterate through nums1 and nums2 respectively.
4. Compare elements and push the smaller one into the `merge` array.
5. After one array is fully iterated, push the remaining elements of the other array.
6. Now we find the median:
    - If merged array size is even → take the average of the two middle elements.
    - If merged array size is odd → return the middle element.
7. Return the median as a floating point number.

Time Complexity: O(n + m) — where n and m are the sizes of nums1 and nums2.
Space Complexity: O(n + m) — for the merged array.
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge;
        int i = 0, j = 0;

        while(i < nums1.size() && j < nums2.size()) {
            if(nums1[i] < nums2[j]) {
                merge.push_back(nums1[i]);
                i++;
            } else {
                merge.push_back(nums2[j]);
                j++;
            }
        }

        while(j < nums2.size()) {
            merge.push_back(nums2[j]);
            j++;
        }

        while(i < nums1.size()) {
            merge.push_back(nums1[i]);
            i++;
        }

        int mergeSize = merge.size();
        if(mergeSize % 2 == 0) {
            int n1 = mergeSize / 2;
            int n2 = n1 - 1;
            return ((float)(merge[n1] + merge[n2]) / 2);
        } else {
            return (float)(merge[mergeSize / 2]);
        }
    }
};
