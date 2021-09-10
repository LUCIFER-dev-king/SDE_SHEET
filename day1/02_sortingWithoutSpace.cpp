//2.Sort an array of 0's 1's 2's without using extra spaing or sorting algo
//https://leetcode.com/problems/sort-colors/

//Bruteforce
#include <bits/stdc++.h>
using namespace std;
class Solutio1
{
public:
    void swap(int *xp, int *yp)
    {
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
    }
    void sortColors(vector<int> &nums)
    {
        int min;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            min = i;
            int temp, j;
            for (j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] < nums[min])
                {
                    min = j;
                }
            }
            swap(&nums[min], &nums[i]);
        }
    }
};

//Optimal Time O(N) and Space: O(1)
class Solution2
{
public:
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;

        while (mid <= high)
        {
            switch (nums[mid])
            {
            case 0:
                swap(&nums[low++], &nums[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(&nums[mid], &nums[high--]);
                break;
            }
        }
    }
};
