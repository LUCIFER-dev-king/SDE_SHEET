// https://leetcode.com/problems/longest-consecutive-sequence/

#include <bits/stdc++.h>
using namespace std;

//BruteForce
// This would be sort it and linearly iterate to find ele and cnt until n+1 exists then max(cnt, longCnt)
// Tc -> O(nlogN) + O(N) Sp -> O(N)

//Optimal TC-> O(N) + O(N) + O(N)=>O(3N) sp->O(N)
class Solution
{
public:
  int longestConsecutive(vector<int> &nums)
  {
    set<int> s;

    for (auto n : nums)
      s.insert(n);

    int longCnt = 0;
    for (auto n : nums)
    {
      if (!s.count(n - 1))
      {
        int shortCnt = 1, m = n;
        while (s.count(m + 1))
        {
          m += 1;
          shortCnt += 1;
        }

        longCnt = max(longCnt, shortCnt);
      }
    }

    return longCnt;
  }
};
