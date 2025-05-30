/* Leetcode 11 - Container With Most Water */

#include <iostream>
#include <vector>
using namespace std;

/*
Approach 1 (Optimized - Two Pointer):
1. Initialize two pointers — `i` at the start, `j` at the end of the array.
2. While `i < j`, do the following:
   a. Calculate the volume:
      - Use the shorter line between height[i] and height[j].
      - Multiply by the width (j - i).
   b. Update `maxVol` with the maximum seen so far.
   c. Move the pointer that is at the shorter height:
      - If height[i] < height[j], increment `i`.
      - Else, decrement `j`.
3. Loop continues until `i >= j`.
4. Return the `maxVol`.

Time Complexity: O(n) — single pass through the array.
Space Complexity: O(1) — only a few variables used.
*/

class SolutionOptimized {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxVol = 0;

        while(i < j) {
            int vol = min(height[i], height[j]) * (j - i);
            maxVol = max(maxVol, vol);

            if(height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return maxVol;
    }
};


/*
Approach 2 (Brute Force):
1. Try every possible pair of lines (i, j) in the array.
2. For each pair, calculate the volume:
   - Take the minimum height between height[i] and height[j].
   - Multiply by the width (which is abs(j - i)).
3. Track the maximum volume seen so far in a variable `maxVol`.
4. Return `maxVol` at the end.

Time Complexity: O(n^2) — because we check every pair.
Space Complexity: O(1) — no extra space used.


class Solution {
public:
    int maxAreaBruteForce(vector<int>& height) {
        int maxVol = 0;

        for(int i = 0; i < height.size(); i++) {
            for(int j = i + 1; j < height.size(); j++) {
                int vol = min(height[i], height[j]) * (j - i);
                maxVol = max(maxVol, vol);
            }
        }

        return maxVol;
    }
};

*/