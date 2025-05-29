/* Best time to buy and sell a stock */

/* approach 1 (Optimal: Time Complexity - O(N), Space Complexity - O(1))

EXPLANATION:
1. This is an optimal one-pass solution.
2. We iterate through the prices array once.
3. We track the minimum price encountered so far (min).
4. At each step, we calculate the profit if we sold the stock at the current price.
5. If this profit is greater than the previously recorded max profit, we update it.
6. This ensures we always buy at the lowest price seen so far and sell at the highest after that.
*/

#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int MaxProfit = 0;
        int min = INT_MAX;
        for(int i = 0; i < prices.size(); i++) {
            if(prices[i] < min) {
                // Update the minimum price if current price is lower
                min = prices[i];
            } else {
                // Calculate profit and update max profit if it's greater
                if(prices[i] - min > MaxProfit) {
                    MaxProfit = prices[i] - min;
                }
            }
        }
        return MaxProfit;
    }
};

/* approach 2 (Won't be accepted as it exceeds the time complexity - O(N^2))

EXPLANATION:
1. Brute force method 
2. i represents the day to buy stock, j represents the day to sell stock 
3. Find the difference between prices[j] and prices[i]
4. The maximum difference is the max profit possible 

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max=0;
        for(int i=0 ; i<prices.size();i++){
            for(int j = i ; j< prices.size() ; j++){
                int n = prices[j]-prices[i];
                if(n>max){
                    max=n;
                }
            }
        }
        return max;     
    }
};
*/
