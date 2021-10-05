#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/rotate-image/solution/

//My approach but it is WE coz it works upto 4*4 matrix. tc o(n2) sp o(1)
//[[1,2,3,4,5],[6,7,8,9,10],[11,12,13,14,15],[16,17,18,19,20],[21,22,23,24,25]]
class Solution1
{
public:
  void rotate(vector<vector<int>> &matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++)
    {

      int j = n - 1 - i;
      if (i > j + 1)
      {
        for (j = n - 2; j >= 0; j--)
        {

          swap(matrix[i][j], matrix[j][m - i - 1]);
        }
      }
      else
      {
        for (j = n - 1 - i; j >= 0; j--)
        {

          swap(matrix[i][j], matrix[j][m - i - 1]);
        }
      }
      // cout<<endl;
    }
  }
};

//Transpose matrix and reverse it. tc->o(n2) + o(n2), sp->o(1)
class Solution2
{
public:
  void rotate(vector<vector<int>> &matrix)
  {
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++)
    {
      for (int j = i + 1; j < n; j++)
        swap(matrix[i][j], matrix[j][i]);
    }

    for (int i = 0; i < m; i++)
      reverse(matrix[i].begin(), matrix[i].end());
  }
};

//roatetion tc o(n) sp O(1) the fatest 100% coz each cell visited only once.

class Solution
{
public:
  void rotate(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    for (int i = 0; i < (n + 1) / 2; i++)
    {
      for (int j = 0; j < n / 2; j++)
      {
        int temp = matrix[n - 1 - j][i];
        matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
        matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];
        matrix[j][n - 1 - i] = matrix[i][j];
        matrix[i][j] = temp;
      }
    }
  }
};