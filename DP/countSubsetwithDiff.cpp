#include<iostream>
#include<vector>
#include<bits/stdc++.h>

using namespace std ;

static int t[5][8] ;

int getSubsetCount(vector<int>& arr, int Sum, int n)
{
	for(int i = 0 ; i <= n ; i++)
		t[i][0] = 1 ;

	for(int i = 1 ; i <= Sum ; i++)
		t[0][i] = 0 ;

	for(int i = 1 ; i < n+1 ; i++)
	{
		for(int j = 1 ; j < Sum+1 ; j++)
		{
			if(arr[i-1] <= j)
				t[i][j] = t[i-1][j-arr[i-1]] + t[i-1][j] ;
			else 
				t[i][j] = t[i-1][j] ;
		}
	} 

	return t[n][Sum] ;
}

int getSubsets(vector<int>& arr, int diff)
{
	int S1, S2 ;
	int sum = 0 ;
	for(int ele : arr)
		sum += ele ;
	if((sum+diff) % 2 != 0) return 0 ;
	S1 = (sum+diff)/2 ;
	int n = arr.size() ;
	int count = getSubsetCount(arr, S1, n) ;
	return count ;
}

int main()
{
	vector<int> arr {1, 2, 1, 3} ;
	int diff ;
	cout<<"Enter the difference value "<<endl ;
	cin>>diff ;
	int subsets = getSubsets(arr, diff) ;
	cout<<"No of subsets with difference "<<diff<<" is "<<subsets<<endl ;
	return 0 ;
}