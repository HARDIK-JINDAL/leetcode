/* Leetcode 912 - Sort an Array (Merge Sort Algorithm) */

#include <vector>
using namespace std;

/*
Approach (Merge Sort - Divide and Conquer):
1. We are given an unsorted array and need to return a sorted version of it.
2. We use Merge Sort - a divide and conquer algorithm that:
   a. Recursively divides the array into two halves until we reach single elements.
   b. Then we merge the sorted halves back together in sorted order.
3. This is a stable and reliable O(n log n) sorting algorithm.

Time Complexity:
- O(n log n) → where n is the size of the array.
  - Because we divide the array log(n) times, and at each level we merge in O(n).

Space Complexity:
- O(n) → due to the use of temporary vector `b` in each merge step.
*/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // Call merge sort on the full array
        mergeSort(nums , 0 , nums.size()-1);
        return nums;
    }

    // Recursive Merge Sort function
    void mergeSort(vector<int>&nums , int lb , int ub){
        if(lb<ub){
            int mid = (lb+ub)/2;
            mergeSort(nums,lb,mid);//sort left
            mergeSort(nums,mid+1,ub);//sort right
            merge(nums , lb , mid , ub);//merge both sorts
        }
    }

    void merge(vector<int>&nums,int lb , int mid , int ub){
        int i = lb , j = mid+1 , k = 0;
        vector<int> b(ub - lb + 1); // Temporary array to store merged elements

        // Merge while both halves have elements
        while(i<=mid&&j<=ub){
            if(nums[i]<=nums[j]){
                b[k]=nums[i];
                i++;k++;
            }else{
                b[k]=nums[j];
                j++;k++;
            }
        }

        // Copy remaining elements
        if(i>mid){
            while(j<=ub){
                b[k]=nums[j];
                j++;k++;
            }
        }else if(j>ub){
            while(i<=mid){
                b[k]=nums[i];
                k++;i++;
            }
        }

        // Copy sorted values back to original array
        for (int p = 0; p < b.size(); ++p) {
            nums[lb + p] = b[p];
        }

    }
};