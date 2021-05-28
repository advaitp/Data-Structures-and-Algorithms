#include<iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std ;

static int t[5][8] ;


int knapSack(vector<int>& val, vector<int>& wt, int W, int n)
{
	if(n == 0 || W == 0)
		return 0 ;

	if(t[n][W] != -1) return t[n][W] ;

	if(wt[n-1] <= W) 
		t[n][W] = max(val[n-1]+knapSack(val, wt, W - wt[n-1], n-1), knapSack(val, wt, W, n-1)) ;
	else
		t[n][W] = knapSack(val, wt, W, n-1) ;

	return t[n][W] ;
} 

int main()
{
	vector<int> val {1, 4, 5, 7} ;
	vector<int> wt {1, 3, 4, 5} ;
	int n, W ; 
	
	memset(t, -1, sizeof(t)) ;
	n = val.size() ;
	W = 7 ;


	int maxProfit = knapSack(val, wt, W, n) ;
	cout<<"Max Profit incurred "<<maxProfit<<endl ;

	return 0 ;
}