#include <bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/majority-element/

//Brutefore approach:
/*This approach is iterate over all element and count it and find it is greater than n/2
  TC -> O(N2) SP -> O(1)
*/

//This uses hash map tc O(N) and sp O(N)
class Solution1
{
public:
  int majorityElement(vector<int> &nums)
  {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
      map[nums[i]]++;
    }

    unordered_map<int, int>::iterator it;

    for (it = map.begin(); it != map.end(); it++)
    {
      if (it->second > (nums.size() / 2))
        return it->first;
    }

    return 0;
  }
};

//Boyer-Moore Voting Algorithm tc->O(N) sp O(1)
class Solution2
{
public:
  int majorityElement(vector<int> &nums)
  {

    int cnt = 0, ele;
    for (int i = 0; i < nums.size(); i++)
    {
      if (cnt == 0)
        ele = nums[i];
      if (nums[i] == ele)
        cnt++;
      else
        cnt--;
    }

    return ele;
  }
};