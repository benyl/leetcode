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

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
  // max profit that can only buy and sell once
  int maxProfitOnce(vector<int> &prices) {
    if(prices.size()<2) return 0;

    int min = prices[0];
    int maxProfit = 0;

    for(int i=0; i<prices.size(); i++)
    {
      int profit = prices[i] - min;
      min = (min<prices[i])? min : prices[i];
      maxProfit = (maxProfit>profit)? maxProfit : profit;
    }

      return maxProfit;
  }  // end of: maxProfit(vector<int> &prices) {

  // max profit that can only buy and sell multiple times
  int maxProfitMulti(vector<int> &prices) {
    if(prices.size()<2) return 0;

    int maxProfit = 0;
    for(int i=1; i<prices.size(); i++)
    {
      if(prices[i] > prices[i-1])
        maxProfit += prices[i] - prices[i-1];
    }

    return maxProfit;
  }  // end of: maxProfit(vector<int> &prices) {

  // max profit that can only buy and sell multiple twice
  int maxProfitTwice(vector<int> &prices) {
    if(prices.size()<2) return 0;

    vector<int> maxProfitE; // max profit before i-th day
    vector<int> maxProfitS; // max profit after i-th day
        
    int maxProfit = 0;
    int min = prices[0];
    for(int i=0; i<prices.size(); i++)
    {
      int profit = prices[i] - min;
      min = (min<prices[i])? min : prices[i];
      maxProfit = (maxProfit>profit)? maxProfit : profit;
      maxProfitE.push_back(maxProfit);
      maxProfitS.push_back(0);
    }

    int max = prices[prices.size()-1];
    maxProfit = 0;
    for(int i=prices.size()-1; i>=0; i--)
    {
      int profit = max - prices[i];
      max = (max>prices[i])? max : prices[i];
      maxProfit = (maxProfit>profit)? maxProfit : profit;
      maxProfitS[i] = maxProfit;
    }

    maxProfit = 0;
    for(int i=0; i<prices.size(); i++)
    {
      if(maxProfitE[i] + maxProfitS[i] > maxProfit)
        maxProfit = maxProfitE[i] + maxProfitS[i];
    }

    return maxProfit;
  }  // end of: maxProfit(vector<int> &prices) {
};

template <class T>
void PrintVec(vector<T> vec)
{
  for(int i=0; i<vec.size(); i++)  
  {
    cout << vec[i];
    if(i!=vec.size()-1)
      cout << ", ";
  }
  cout << endl;
}

int main()
{
  int priceArray[] = {1,2,4,2,5,7,2,4,9,0,9};
  vector<int> prices(priceArray,end(priceArray));

  cout << "input: ";
  PrintVec<int>(prices);
  
  Solution sol;
  
  cout << "maxProfitOnce : " << sol.maxProfitOnce(prices) << endl;
  cout << "maxProfitMulti: " << sol.maxProfitMulti(prices) << endl;
  cout << "maxProfitTwice: " << sol.maxProfitTwice(prices) << endl;
  getchar();
  return 0;
}