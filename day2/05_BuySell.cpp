#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/

class Solution
{
public:
  int maxProfit(vector<int> &prices)
  {
    int minP = INT_MAX;

    int maxPr = 0;
    for (int i = 0; i < prices.size(); i++)
    {
      minP = min(minP, prices[i]);
      maxPr = max(maxPr, prices[i] - minP);
    }

    return maxPr;
  }
};

//Edge case in this approach [2,4,1] expOut-> 2 but actualOP=0

//Since we are getting min day and selling the stock.
//But what is need a day to buy and maximze profit
class Solution1
{
public:
  int maxProfit(vector<int> &prices)
  {
    int min = min_element(prices.begin(), prices.end()) - prices.begin();

    int max = prices[min];
    for (int i = min + 1; i < prices.size(); i++)
    {
      if (prices[i] > max)
        max = prices[i];
    }

    return abs(prices[min] - max);
  }
};