#include <bits/stdc++.h>
using namespace std;
//1. Find the duplicate in an array of N+1 integers.

/*Bruteforce approach */
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

/*Cycle Detection using Floyd's algorithm*/
class Solution1
{
public:
  int findDuplicate(vector<int> &nums)
  {
    int tortoise = nums[0];
    int hare = nums[0];

    do
    {
      tortoise = nums[tortoise];
      hare = nums[nums[hare]];
    } while (tortoise != hare);

    tortoise = nums[0];
    while (tortoise != hare)
    {
      tortoise = nums[tortoise];
      hare = nums[hare];
    }

    return hare;
  }
};

/*Faster tgeb 64% and Space Efficient 91.29%*/
class Solution2
{
public:
  int findDuplicate(vector<int> &nums)
  {

    for (int i = 0; i < nums.size(); i++)
    {
      if (nums[abs(nums[i])] < 0)
        return abs(nums[i]);
      else
        nums[abs(nums[i])] = nums[abs(nums[i])] * -1;
    }

    return 0;
  }
};