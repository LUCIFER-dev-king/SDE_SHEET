//https://leetcode.com/problems/4sum/

#include <bits/stdc++.h>
using namespace std;

//Bruteforce appprach is TC->O(N3) SP -> O(N)
//Step1: First iterate with i and j and k, then  target - (i+j+k).
//Then find do binary search from k+1 to n-1 element to get target
//Step2: After finding first set then increament j++ repeat step 1. Again incr i++ repeat.
// Store the [elements] in hash set.

//Optimal would TC O(N3) sp->O(1)
//using i and j to iterate and l and r to iterate j+i.
class Solution
{
public:
  vector<vector<int>> fourSum(vector<int> &nums, int target)
  {
    int n = nums.size();
    vector<vector<int>> v;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n; i++)
    {
      for (int j = i + 1; j < n; j++)
      {
        int l = j + 1, r = n - 1;
        int x = target - (nums[j] + nums[i]);
        while (l < r)
        {
          int y = nums[l] + nums[r];
          if (y == x)
          {
            vector<int> temp;
            temp.push_back(nums[i]);
            temp.push_back(nums[j]);
            temp.push_back(nums[l]);
            temp.push_back(nums[r]);
            v.push_back(temp);

            while (l < r && nums[l] == temp[2])
              ++l;

            while (l < r && nums[r] == temp[3])
              --r;
          }
          else if (y > x)
            r--;
          else
            l++;
        }

        while (j + 1 < n && nums[j + 1] == nums[j])
          ++j;
      }

      while (i + 1 < n && nums[i + 1] == nums[i])
        ++i;
    }

    return v;
  }
};