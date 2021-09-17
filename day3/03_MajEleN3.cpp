#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/majority-element-ii/

//Brueteforce as same N/2

//hash map as sanme as N/2
class Solution
{
public:
  vector<int> majorityElement(vector<int> &nums)
  {
    int cnt = 0, ele;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
      if (cnt == 0)
        ele = nums[i];
      if (nums[i] == ele)
        cnt++;
      else
        cnt--;
    }

    return ans;
  }
};

//BoreMoor voging algo.
class Solution1
{
public:
  vector<int> majorityElement(vector<int> &nums)
  {
    int num1 = -1, num2 = -1, cnt1 = 0, cnt2 = 0;
    vector<int> ans;
    for (int i = 0; i < nums.size(); i++)
    {
      if (num1 == nums[i])
        cnt1++;
      else if (num2 == nums[i])
        cnt2++;
      else if (cnt1 == 0)
      {
        num1 = nums[i];
        cnt1 = 1;
      }
      else if (cnt2 == 0)
      {
        num2 = nums[i];
        cnt2 = 1;
      }
      else
        cnt1--;
      cnt2--;
    }

    cnt1 = cnt2 = 0;
    for (auto num : nums)
    {
      if (num1 == num)
        cnt1++;
      else if (num2 == num)
        cnt2++;
    }

    if (cnt1 > nums.size() / 3)
      ans.push_back(num1);

    if (cnt2 > nums.size() / 3)
      ans.push_back(num2);

    return ans;
  }
};