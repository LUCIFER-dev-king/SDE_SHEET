#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/subarray-sum-equals-k/solution/

//BruteForce tc O(N3) sp O(1)
class Solution1
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    int cnt = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j <= n; j++)
      {
        int sum = 0;
        for (int z = i; z < j; z++)
        {
          sum += nums[z];
        }

        if (sum == k)
          cnt++;
      }
    }
    return cnt;
  }
};

// O(N2)
class Solution2
{
public:
  int subarraySum(vector<int> &nums, int k)
  {
    int cnt = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
      int sum = 0;
      for (int j = i; j < n; j++)
      {

        sum += nums[j];

        if (sum == k)
          cnt++;
      }
    }
    return cnt;
  }
};
