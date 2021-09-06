#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  int findDuplicate(vector<int> &nums)
  {
    int n = nums.size();
    vector<int> temp(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
      if (temp[nums[i]] != 0)
      {
        return nums[i];
      }
      temp[nums[i]]++;
    }

    return 0;
  }
};