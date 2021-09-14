#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/reverse-only-letters/
// isalpha() can be used.

// TC-> o(n) S.p -> o(1)
/*There is another approach with stack with o(n) time and o(n) space
  inituition : insert char to stack since it store FILO,
  when we pop() from stack if gives reverse order
*/
class Solution
{
public:
  string reverseOnlyLetters(string s)
  {

    int l = 0, r = s.length() - 1;

    while (l < r)
    {
      if ((s[l] >= 65 && s[l] <= 122) && (s[r] >= 65 && s[r] <= 122))
      {
        if ((s[l] >= 91 && s[l] <= 96))
        {
          l++;
        }
        else if ((s[r] >= 91 && s[r] <= 96))
        {
          r--;
        }
        else
        {
          char temp = s[l];
          s[l] = s[r];
          s[r] = temp;

          cout << s[l] << s[r];
          l++;
          r--;
        }
      }
      else if ((s[l] <= 64))
      {
        l++;
      }
      else if ((s[r] <= 64))
      {
        r--;
      }
    }

    return s;
  }
};