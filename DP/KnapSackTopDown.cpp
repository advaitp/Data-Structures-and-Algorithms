#include<iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std ;

static int t[5][8] ;

int knapSack(vector<int>& val, vector<int>& wt, int W, int n)
{
	for(int i = 0 ; i < n+1 ; i++)
	{
		for(int j = 0 ; j < W+1 ; j++)
		{
			if(i == 0 || j == 0) t[i][j] = 0 ;
		}
	}

	for(int i = 1 ; i < n+1 ; i++)
	{
		for(int j = 1 ; j < W+1 ; j++)
		{
			if(wt[i-1] <= j)
				t[i][j] = max(val[i-1]+t[i-1][j - wt[i-1]], t[i-1][j]) ;

			else
				t[i][j] = t[i-1][j];
		}
	}

	return t[n][W] ;

}

int main()
{
	vector<int> val {1, 4, 5, 7} ;
	vector<int> wt {1, 3, 4, 5} ;
	int n, W ; 
	
	n = val.size() ;
	W = 7 ;

	

	int maxProfit = knapSack(val, wt, W, n) ;
	cout<<"Max Profit incurred "<<maxProfit<<endl ;

	return 0 ;
}