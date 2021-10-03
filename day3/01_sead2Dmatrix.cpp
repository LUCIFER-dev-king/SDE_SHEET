#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rotate-image/solution/

// Tc -> O(n * log2m) sp -> o(1)
class Solution1
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++)
    {
      if (binary_search(matrix[i].begin(), matrix[i].end(), target))
        return true;
    }

    return false;
  }
};

// tc O(mn) sp O(1)
class Solution2
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {
    int i = 0, j = matrix[0].size() - 1;

    while (i < matrix.size() && j >= 0)
    {
      if (matrix[i][j] == target)
        return true;

      if (matrix[i][j] > target)
        j--;
      else
        i++;
    }

    return false;
  }
};

// TC->O(log2(mn)) sp->o(1)
class Solution
{
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target)
  {

    if (matrix.empty())
      return false;

    int m = matrix.size();
    int n = matrix.front().size();
    if (n == 0)
      return false;

    for (int l = 0, h = m * n - 1; l <= h;)
    {
      int mid = l + (h - l) / 2;
      int i = mid / n, j = mid % n;

      if (matrix[i][j] == target)
        return true;
      if (matrix[i][j] > target)
      {
        h = mid - 1;
      }
      else
      {
        l = mid + 1;
      }
    }

    return false;
  }
};