/*
Best Time to Buy and Sell Stock
Say you have an array for which the i-th element is the price of a given stock on day i.

(http://leetcode.com/onlinejudge#question_121)
Problem I:
If you were only permitted to complete at most one transaction 
(ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example Input: [1,2,4,2,5,7,2,4,9,0,9]
Expected Result: 9

(http://leetcode.com/onlinejudge#question_122)
Problem II:
Design an algorithm to find the maximum profit. You may complete as many transactions as you like
(ie, buy one and sell one share of the stock multiple times). 
However, you may not engage in multiple transactions at the same time 
(ie, you must sell the stock before you buy again).

Example Input: [1,2,4,2,5,7,2,4,9,0,9]
Expected Result: 24

(http://leetcode.com/onlinejudge#question_123)
Problem III:
Design an algorithm to find the maximum profit. You may complete at most two transactions.

Example Input: [1,2,4,2,5,7,2,4,9,0,9]
Expected Result: 17
*/

// =========================================================
// Best Time to Buy and Sell Stock I
// max profit that can only buy and sell once
// 60 milli secs pass large judge
// time complexity o(n), space complexity o(1)

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int minPrice=INT_MAX, profit=0;
        for(int i=0; i<prices.size(); ++i) {
            profit = max(profit, prices[i]-minPrice);
            minPrice = min(minPrice, prices[i]);
        }
        return profit;
    }
};

// =========================================================
// Best Time to Buy and Sell Stock II
// max profit that can only buy and sell multiple times
// 52 milli secs pass large judge
// time complexity o(n), space complexity o(1)

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        for(int i=1; i<prices.size(); ++i)
            profit += max(0, prices[i]-prices[i-1]) ;
        return profit;
    }
};

// =========================================================
// Best Time to Buy and Sell Stock III, dynamic programming
// max profit that can only buy and sell at most twice
// 56 milli secs pass large judge
// time complexity o(n), space complexity o(n)

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if(prices.size()<2) return 0;
        
        vector<int> profit1(prices.size(), 0); // max profit before i-th day
        int minPrices = prices[0];
        
        for(int i=1; i<prices.size(); ++i) {
            minPrices = min(minPrices, prices[i]);
            profit1[i] = max(profit1[i-1], prices[i]-minPrices); // store profit1 in memory
        }
        
        int maxPrices = prices.back(), sumProfit = 0;
        int profit2 = 0; // max profit after i-th day
        
        for(int i=prices.size()-2; i>=0; --i) {
            maxPrices = max(maxPrices, prices[i]);
            profit2 = max(profit2, maxPrices-prices[i]); // calculate profit2
            
            sumProfit = max(sumProfit, profit2+profit1[i]); // sum the two profits
        }
        
        return sumProfit;
    }
};
