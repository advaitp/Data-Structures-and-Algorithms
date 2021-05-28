#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std ;

static int t[5][8] ;
// TOP DOWN APPROACH 
int unboundedKnapSack(vector<int>& val, vector<int>& wt, int W, int n)
{
	for(int i = 0 ; i <= W ; i++)
		t[0][i] = 0 ;

	for(int j = 0 ; j <= n ; j++)
		t[j][0] = 0 ;

	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= W ; j++)
		{
			if(wt[i-1] <= j)
			{
				// DIFF BETWEEN 0/1 KNAPSACK AND UNBOUNDED KNAPSACK 
				t[i][j] = max(val[i-1]+t[i][j - wt[i-1]], t[i-1][j]) ;
			}
			else
				t[i][j] = t[i-1][j] ;
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

	int maxProfit = unboundedKnapSack(val, wt, W, n) ;
	cout<<"Max Profit incurred "<<maxProfit<<endl ;

	return 0 ;
}