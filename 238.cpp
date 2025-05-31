/* Leetcode 238 - Product of Array Except Self */

#include<iostream>
#include<vector>
using namespace std;

/*
Approach 1 (Optimized - Prefix and Suffix Multiplication):
1. We want to calculate the product of all elements except the current index.
2. Instead of recalculating every time, we store:
   - `prefix[i]`: product of all elements to the left of `i`
   - `suffix[i]`: product of all elements to the right of `i`
3. We build the answer in two passes:
   - First pass (left to right): fill `answer[i]` with prefix product
   - Second pass (right to left): multiply existing `answer[i]` with suffix product
4. We use only one array `answer` to store both steps, optimizing space.

Time Complexity: O(n)
Space Complexity: O(1) — ignoring output array
*/

class SolutionOptimized {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        answer.push_back(1); // answer[0] = 1 as no element before it
        int product = 1;
        // First pass: calculate prefix product
        for(int i = 0 ; i < nums.size() - 1 ; i++){
            product *= nums[i];
            answer.push_back(product);
        }
        product = 1;
        // Second pass: calculate suffix product and update answer
        for(int i = nums.size() - 1 ; i >= 0 ; i--){
            answer[i] = answer[i] * product;
            product *= nums[i];
        }
        return answer;
    }
};

/*
Approach 2 (Brute Force):
1. For each element in the array, calculate the product of all elements except the current one.
2. Use two nested loops:
   - Outer loop to iterate through each index `j`.
   - Inner loop to multiply all elements except index `j`.
3. Push the result into the answer array for each index.
4. Time Complexity is high due to repeated calculations.

Time Complexity: O(n^2)
Space Complexity: O(n) — to store result


class SolutionBrute {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        for(int j = 0 ; j < nums.size(); j++){
            int product = 1;
            for(int i = 0 ; i < nums.size(); i++){
                if(j != i){
                    product *= nums[i];
                }
            }
            answer.push_back(product);
        }
        return answer;
    }
};
*/
