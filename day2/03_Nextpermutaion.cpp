#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/next-permutation/
//For intuition refer note

#include <algorithm>
class Solution
{
public:
  void nextPermutation(vector<int> &nums)
  {

    int n = nums.size(), i, j;

    for (i = n - 2; i >= 0; i--)
    {
      if (nums[i] < nums[i + 1])
        break;
    }
    cout << i;
    if (i < 0)
    {
      reverse(nums.begin(), nums.end());
    }
    else
    {
      for (j = n - 1; j > i; j--)
      {
        if (nums[j] > nums[i])
        {

          break;
        }
      }
      swap(nums[i], nums[j]);
      reverse(nums.begin() + i + 1, nums.end());
    }
  }
};

//This may not crct but for very next permuation
class Solution1
{
public:
  void swap()
  {
  }

  void nextPermutation(vector<int> &nums)
  {

    for (int i = nums.size(); i > 1; i--)
    {
      if (nums[i] > nums[i - 1])
      {
        int temp = nums[i];
        nums[i] = nums[i - 1];
        nums[i - 1] = temp;
        break;
      }

      else if (i == 2)
      {
        sort(nums.begin(), nums.end());
        break;
      }
    }
  }
};
