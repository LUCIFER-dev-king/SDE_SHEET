#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/pascals-triangle/submissions/
// bruteforce tc o(n2) and sp o(n2)

class Solution
{
public:
  vector<vector<int>> generate(int numRows)
  {
    vector<vector<int>> vect;
    for (int i = 1; i <= numRows; i++)
    {
      vector<int> temp(i, 1);
      if (i > 2)
        for (int j = 1; j < i - 1; j++)
        {
          temp[j] = vect[i - 2][j - 1] + vect[i - 2][j];
        }
      vect.push_back(temp);
    }

    return vect;
  }
};

//optimal tc O(n2) and sp O(1)  using binomial coefficient.
//https://www.geeksforgeeks.org/pascal-triangle/

class Solution1
{
public:
  void generate(int n)
  {

    for (int line = 1; line <= n; line++)
    {
      int C = 1; // used to represent C(line, i)
      for (int i = 1; i <= line; i++)
      {

        // The first value in a line is always 1
        cout << C << " ";
        C = C * (line - i) / i;
      }
      cout << "\n";
    }
  }
}

;