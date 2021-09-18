// https://leetcode.com/problems/set-matrix-zeroes/

#include <bits/stdc++.h>
using namespace std;

// Straight forward solution. Tc->O(m*n + m + n) sp O(m+n)
class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> copy;
    copy = matrix;
    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (matrix[i][j] == 0)
        {
          for (int k = 0; k < m; k++)
          {
            copy[k][j] = 0;
          }
          for (int k = 0; k < n; k++)
          {
            copy[i][k] = 0;
          }
        }
      }
    }

    matrix = copy;
  }
};

// Optimal solution. Tc-> O(n2) SP->O(1)
//Edge Case: [[1,2,3,4],[5,0,7,8],[0,10,11,12],[13,14,15,0]]
class Solution1
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();
    bool isFirst = false;
    for (int i = 0; i < m; i++)
    {
      if (matrix[i][0] == 0)
        isFirst = true;
      for (int j = 1; j < n; j++)
      {
        if (matrix[i][j] == 0)
        {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }

    for (int i = 1; i < m; i++)
    {
      for (int j = 1; j < n; j++)
      {
        if (matrix[i][0] == 0 || matrix[0][j] == 0)
        {
          matrix[i][j] = 0;
        }
      }
    }

    if (matrix[0][0] == 0)
    {
      for (int i = 0; i < n; i++)
        matrix[0][i] = 0;
    }

    if (isFirst)
    {
      for (int i = 0; i < m; i++)
        matrix[i][0] = 0;
    }
  }
};