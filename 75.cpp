/* Leetcode 75*/

#include <iostream>
#include <vector>
using namespace std;

/*
*Approach: Dutch National Flag algorithm
* 1. Use three pointers: low, mid, and high.
* 2. low: position for next 0
* 3. mid: current index being checked
* 4. high: position for next 2 
* We swap values into correct position based on their value:
*  - If nums[mid] == 0: swap with low, move both pointers.
*  - If nums[mid] == 1: just move mid.
*  - If nums[mid] == 2: swap with high, move high only.
* Time Complexity: O(n) — Each element is looked at most once.
* Space Complexity: O(1) — No extra space is used. 
*/

class Solution {
public:

    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};
/*Approach:2. Use merge sort to sort the entire array.
2. Recursively divide the array into halves.
3. Merge the sorted halves using extra space.
Time Complexity: O(n log n)
Space Complexity: O(n) — due to temporary vector during merging.
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
    }
    void mergeSort(vector<int>& nums,int lb,int ub){
        if(lb<ub){
            int mid = (lb+ub)/2;
            mergeSort(nums,lb,mid);
            mergeSort(nums,mid+1,ub);
            merge(nums,lb,mid,ub);
        }
    }
    void merge(vector<int>& nums,int lb , int mid , int ub){
        int i = lb , j = mid+1 ;
        vector<int> b;
        while(i<=mid&&j<=ub){
            if(nums[i]<=nums[j]){
                b.push_back(nums[i]);
                i++;
            }else{
                b.push_back(nums[j]);
                j++;
            }
        }
        while(i<=mid){
            b.push_back(nums[i]);
            i++;
        }while(j<=ub){
            b.push_back(nums[j]);
            j++;
        }
        for(int i = 0 ; i < b.size() ; i++){
            nums[lb + i] = b[i];  
        }

    }
};