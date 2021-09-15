#include <bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/powx-n/submissions/

//Bruteforce tc -> O(n) sp O(1)
class Solution1
{
public:
  double myPow(double x, int n)
  {
    double ans = 1;
    if (n >= 0)
    {
      while (n--)
      {
        ans *= x;
      }
    }
    else if (n < 0)
    {
      while (n++)
      {
        ans *= x;
      }
      ans = 1 / ans;
    }
    return ans;
  }
};

//Optimal log2N solution
class Solution
{
public:
  double myPow(double x, int n)
  {
    double ans = 1;

    long long int tt = n;
    if (tt < 0)
      tt = -1 * tt;

    while (tt > 0)
    {
      if (tt % 2)
      {
        ans = x * ans;
        tt--;
      }
      else
      {
        x *= x;
        tt = tt / 2;
      }
    }

    if (n < 0)
      return 1.0 / ans;

    return ans;
  }
};