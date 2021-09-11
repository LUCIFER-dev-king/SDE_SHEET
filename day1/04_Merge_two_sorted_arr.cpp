//4. Merge two sorted arrays with O(1) extra space
//Bruteforce
#include <bits/stdc++.h>
using namespace std;
// 1.store the arr1 and arr2 to temp;
// 2.and sort the temp.3.store it to the arr1 untiml m and to arr2 until n.

//     T.C->O(nLogn) +
//     O(N) + O(N) + O(N) S.P->O(N)

//Optimal T.C -> O(n+m log(n+m)) S.P -> O(1)
// int i = 0;
// j = 0;
// k = n - 1;
// while (i <= k && j <= m)
// {
//   if (arr1[i] < arr[j])
//     i++;
//   else
//     swap(arr2[j++], arr1[k--]);
// }
// sort(arr1, arr1 + m)
//     sort(arr2, arr2 + n)