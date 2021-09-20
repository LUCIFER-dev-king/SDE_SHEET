// https://leetcode.com/problems/two-sum/
#include <bits/stdc++.h>
using namespace std;

//Brutefrce is tc O(N2) sp O(1)

//TC-> O(N) sp O(N)
class Solution
{
public:
  vector<int> twoSum(vector<int> &nums, int target)
  {
    vector<int> vect;
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++)
    {
      int x = target - nums[i];

      if (map.find(x) == map.end())
      {
        map.insert(make_pair(nums[i], i));
      }
      else
      {
        vect.push_back(map[x]);
        vect.push_back(i);
        return vect;
      }
    }

    return vect;
  }
};

//Another is Two pointer approact first sort the array and incr decr l and r.
//TC = O(N) sp = O(1) if we neglect return arrary.
