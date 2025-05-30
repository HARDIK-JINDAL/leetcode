/* Leetcode 27 - Remove Element */

/*
Approach 1: Also accepted by leetcode 
1. Loop through the array and check if the current element is equal to val
2. If it is, replace it with the last element and reduce the size (n--)
3. Decrement `i` to recheck the current index with the new value
4. Else, increase the count

Risks and Issues:
- Directly changing array size during iteration (`n--`) can be unsafe if not handled carefully.
- Using `i--` inside a loop can cause hard-to-track bugs or infinite loops if edge cases aren't covered.
- Modifies original order of elements (which is fine for this problem but worth noting).

Time Complexity: O(n)
Space Complexity: O(1)

Code:

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        int n = nums.size();
        for(int i = 0 ; i < n; i++){
            if(nums[i] == val){
                nums[i] = nums[n-1];
                i--;
                n--;
            } else {
                count++;
            }
        }
        return count;
    }
};

*/

/*
Approach 2: (Optimal + Safer)
1. Loop through the array from start to end
2. Use a pointer `j` to keep track of where to place the next valid (non-val) element
3. If the current element is not equal to val:
   - assign it to nums[j]
   - increment j
4. Else, skip it (we don't copy val)
5. Return j as the count of elements not equal to val

Advantages:
- No direct mutation of array size while iterating
- No i-- or tricky control flow
- Maintains clarity and safety
- Very efficient

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val){
                // copy the current value to the j-th position
                nums[j] = nums[i];
                j++;
            }
        }

        return j;
    }
};
