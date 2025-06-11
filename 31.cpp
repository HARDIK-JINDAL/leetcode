/* Leetcode 31 – Next Permutation*/

#include <vector>
#include <algorithm>
using namespace std;

/*
Problem Summary:
Given an array of integers representing a permutation of numbers, modify the array to its next permutation in-place. 
If such arrangement is not possible (i.e., it's the highest possible permutation), rearrange it to the lowest (i.e., sorted in ascending order).

1. **Find Pivot**:
   - Traverse from right to left to find the first index `i` such that nums[i] < nums[i+1].
   - This index is the "pivot" — the point where the ascending order breaks from the right.
   - If no such index is found (i.e., array is in descending order), it's the last permutation → reverse the entire array.

2. **Find the Smallest Element Greater Than Pivot**:
   - From the right, find the first element that is greater than nums[pivot].
   - Swap this element with nums[pivot].

3. **Reverse the Suffix**:
   - Reverse the part of the array that comes after the pivot (i.e., from pivot+1 to end).
   - This ensures the suffix is in the lowest possible order.

Time Complexity: O(n) – We traverse the array a few times (all linear operations).
Space Complexity: O(1) – We modify the array in-place without using extra space.
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1 ;
        int n = nums.size();
        for(int i=nums.size()-2 ; i>=0 ; i--){
            if(nums[i]<nums[i+1]){
                pivot = i ; 
                break;
            }
        }
        if(pivot==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i = n-1; i> pivot ; i-- ){
            if(nums[i]>nums[pivot]){
                swap(nums[i],nums[pivot]);
                break;
            }
        }
        int i = pivot+1 , j=n-1;
        while(i<=j){
            swap(nums[i],nums[j]);
            i++;j--;
        }
    }
};