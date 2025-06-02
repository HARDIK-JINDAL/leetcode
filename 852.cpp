/* Leetcode 852 - Peak Index in a Mountain Array*/

#include <iostream>
#include <vector>
using namespace std;

/*
Approach (Binary Search):
1. Initialize two pointers: st = 0 and end = arr.size() - 1.
2. While st <= end, calculate mid = (st + end) / 2.
3. Check if mid is not on the boundary:
   - If arr[mid] is greater than both neighbors, mid is the peak, return mid.
   - If arr[mid] is less than arr[mid + 1], move st to mid + 1 to search right.
   - Else, move end to mid - 1 to search left.
4. Handle boundary cases where mid is 0 or the last index by adjusting pointers accordingly.
5. Return -1 if no peak found (theoretically shouldn't happen for a valid mountain array).

Time Complexity: O(log n) — binary search.
Space Complexity: O(1) — constant extra space.
*/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st = 0, end = arr.size() - 1;
        while (st <= end) {
            int mid = (st + end) / 2;
            if (mid > 0 && mid < arr.size() - 1) {
                if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                    return mid;           // Peak found
                } else if (arr[mid] < arr[mid + 1]) {
                    st = mid + 1;         // Move right if ascending slope
                } else {
                    end = mid - 1;        // Move left if descending slope
                }
            } else if (mid == 0) {
                st = mid + 1;             // Adjust start if mid at left boundary
            } else if (mid == arr.size() - 1) {
                end = mid - 1;            // Adjust end if mid at right boundary
            }
        }
        return -1;                       
    }
};

/* Leetcode 852 - Peak Index in a Mountain Array (Brute Force)

/*
Approach (Linear Search):
1. Iterate from the second element (index 1) to the second last element (index n-2).
2. For each element, check if it is greater than both its neighbors.
3. If yes, return the current index as the peak.
4. If no peak is found during iteration, return -1 (though not expected for valid mountain arrays).

Time Complexity: O(n) — single pass through the array.
Space Complexity: O(1) — no extra space used.
*/

class Solution {
public:
    int peakIndexInMountainArrayBrute(vector<int>& arr) {
        for (int i = 1; i < arr.size() - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                return i;  // Peak found
            }
        }
        return -1;  // No peak found (edge case)
    }
};
