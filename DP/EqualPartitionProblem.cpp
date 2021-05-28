#include<iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std ;

static int t[5][12] ;

bool knapSack(vector<int>& wt, int W, int n)
{
	for (int i = 0; i <= n; i++)
        t[i][0] = true;
 
    for (int i = 1; i <= W; i++)
        t[0][i] = false;

	for(int i = 1 ; i < n+1 ; i++)
	{
		for(int j = 1 ; j < W+1 ; j++)
		{
			if(wt[i-1] <= j)
				t[i][j] = (t[i-1][j - wt[i-1]] || t[i-1][j]) ;

			else
				t[i][j] = t[i-1][j];
		}
	}

	return t[n][W] ;
}

bool isEqualPartition(vector<int>& arr)
{
	int sum = 0 ;
	for(auto ele : arr)
	{
		sum += ele ;
	}

	int n = arr.size() ;
	if(sum % 2 != 0) return false ;
	else return knapSack(arr, sum/2, n) ;

}

int main()
{
	vector<int> arr {1,5,11,3} ;
	int sum = 0 ;

	bool isPossible = isEqualPartition(arr) ;
	if(isPossible)
		cout<<"Equal Partition possible "<<endl ;
	else 
		cout<<"Equal Partition not possible "<<endl ;

	return 0 ;
}