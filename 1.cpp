/* Leetcode 1 - Two Sum */

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

/*
Approach 1 - Hash Map:
1. Create a hash map to store value → index.
2. Loop through the array:
   a. For each value, compute target - current number.
   b. Check if the result exists in the hash map.
   c. If yes, return indices of current number and that complement.
   d. Otherwise, store current number with its index in map.
3. If no pair found, return empty vector.

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;  // number → index

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            if (map.find(complement) != map.end()) {
                return {map[complement], i};
            }
            map[nums[i]] = i;
        }

        return {};
    }
};

/*
Approach 2 - Sorting + Binary Search:
1. Store original indices along with values in a vector of pairs.
2. Sort the vector by values.
3. Loop through each element:
   a. Calculate target - current number.
   b. Use binary search on the rest of the array to find that number.
   c. If found, return original indices of both numbers.
4. If no match, return empty vector.

Time Complexity: O(n log n)
Space Complexity: O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> arr; // pair of <value, original index>
        for (int i = 0; i < nums.size(); ++i) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());  // sort based on value

        for (int i = 0; i < arr.size(); ++i) {
            int complement = target - arr[i].first;
            int index = binarySearch(arr, i + 1, arr.size() - 1, complement);
            if (index != -1) {
                return {arr[i].second, arr[index].second};
            }
        }

        return {};
    }

    // binary search for target value in sorted array of pairs
    int binarySearch(vector<pair<int, int>>& arr, int low, int high, int target) {
        while (low <= high) {
            int mid = (low + high) / 2;
            if (arr[mid].first == target) return mid;
            else if (arr[mid].first < target) low = mid + 1;
            else high = mid - 1;
        }
        return -1;
    }
};

*/

/* 
Approach 3 - Brute Force:
1. Use 2 nested loops to check all possible pairs in the array.
2. For each pair, check if their sum equals the target.
3. If found, return their indices.
4. If no pair found after all iterations, return empty vector.

Time Complexity: O(n^2)
Space Complexity: O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i = 0 ; i < nums.size() ; i++){
            for(int j = i+1 ; j < nums.size() ; j++){
                if(nums[i]+nums[j]==target){
                    return{i,j};
                }
            }
        }
        return{};
    }
};
*/