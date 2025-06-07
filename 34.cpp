/* Leetcode 34 - Find First and Last Position of Element in Sorted Array (Binary Search x2) */

#include <iostream>
#include <vector>
using namespace std;

/*
Approach (Binary Search for First and Last Occurrence):
1. We are given a sorted array and a target element.
2. We need to find the first and last index of the target in the array.
3. We use binary search two times:
   - Once to find the first occurrence of the target.
   - Once to find the last occurrence of the target.
4. For first occurrence:
   - If target is found, move to the left half to see if there's an earlier occurrence.
5. For last occurrence:
   - If target is found, move to the right half to see if there's a later occurrence.
6. If the target is not found, return {-1, -1}.
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> pos = {-1,-1};
        int first = binarysearch(nums,target,true);
        int last = binarysearch(nums,target,false);
        pos[0]=first;
        pos[1]=last;
        return pos;
    }
    int binarysearch(vector<int> &nums , int target , bool isfirst){
        int st=0 , end = nums.size()-1,index=-1;
        

        while(st<=end){
            int mid = (st+end)/2;
            if(nums[mid]==target){
                index=mid;
                if(isfirst){
                    end=mid-1;
                }else{
                    st=mid+1;
                }
            }
            else if(nums[mid]<target){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
        return index;
    }
};