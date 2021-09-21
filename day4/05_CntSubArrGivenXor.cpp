#include <bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/count-number-subarrays-given-xor/

//Bruteforece is imply kadane's algorithm. TC O(n3)->o(n2) sp O(1)
class sol
{
  int fun(vector<int> nums, int target)
  {
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
      int sum = 0;
      for (int j = i; i < nums.size(); j++)
      {
        sum ^= nums[i];

        if (sum == target)
          ans++;
      }
    }
    return ans;
  }
};

// prefix sum prb wtih hashmap. tc o(NlogN) sp(N) may tc can be O(N) if unordered map.
//learn prefix sum prbs to understand this.
#include <bits/stdc++.h>
using namespace std;

long long subarrayXor(int arr[], int n, int m)
{
	long long ans = 0; 
    map<int,int> f;
  	int xorr =0;
  
  	for(int i=0;i<n;i++){
    	xorr ^= arr[i];
        if(xorr==m)
          ans++;
        if(f.find(xorr^m)!=f.end())
          ans += f[xorr^m];
        f[xorr]++;
    }
	return ans;
}

// Driver program to test above function
int main()
{
	int arr[] = { 4, 2, 2, 6, 4 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int m = 6;

	cout << "Number of subarrays having given XOR is "
		<< subarrayXor(arr, n, m);
	return 0;
}
