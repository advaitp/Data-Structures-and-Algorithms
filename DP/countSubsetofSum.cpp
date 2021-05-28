#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std ;

static int t[7][11] ;
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

int main()
{
	vector<int> arr {2, 3, 5, 6, 8, 10} ;
	int Sum = 10 ;
	int n = arr.size() ;
	int count = getSubsetCount(arr, Sum, n) ;
	cout<<"Total Number of Subsets "<<count<<endl ;
	return 0 ;
}