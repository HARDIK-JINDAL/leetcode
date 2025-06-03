/* Leetcode 410 - Split Array Largest Sum (Binary Search on Answer) */

#include <iostream>
#include <vector>
using namespace std;

/*
Approach (Binary Search on Answer Range):
1. We are given an array and need to split it into 'm' subarrays.
2. Our goal is to minimize the largest sum among those subarrays.
3. We use binary search to find this minimum largest sum(if sum = 5 then we search through [0,1,2,3,4,5]):
   - The smallest possible sum is 0 (lower bound).
   - The largest possible sum is the total sum of the array (upper bound).
4. For each mid (potential maximum subarray sum), we check:
   - Is it possible to split the array into <= m parts such that no part exceeds 'mid' amount of pages?
5. If yes → we try a smaller mid (end = mid - 1).
   If no  → we try a larger mid (start = mid + 1).
6. We keep track of the best (smallest) valid answer found.

Time Complexity: O(n * log(sum))
Space Complexity: O(1)
*/

class Solution {
public:
    int splitArray(vector<int>& arr, int m) {
        int sum=0;
        if(m>arr.size()){
            return -1;
        }
        for(int i = 0 ; i<arr.size(); i++){
            sum += arr[i];
        }
        int st = 0 ,end = sum;
        int ans = -1;
        while(st<=end){
            int mid = st+ (end-st)/2;
            if(isValid(arr,arr.size(),m,mid)){
                ans=mid;
                end = mid-1;
            }else{
                st =mid+1;
            }
        }
        return ans;
    }

    bool isValid(vector<int> &arr, int n , int m , int MaxAllowedPages){
        int stu = 1, pages = 0;
        for(int i = 0 ; i < n ; i++){
            if(arr[i] > MaxAllowedPages) return false;
            if(pages + arr[i] <= MaxAllowedPages){
                pages += arr[i];
            }else{
                stu++;
                pages = arr[i]; 
            }
        }
        return stu <= m;
    }

};
