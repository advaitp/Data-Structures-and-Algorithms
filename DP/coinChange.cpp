#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std ;

static int t[4][5] ;

int getCount(vector<int>& wt, int W, int n)
{
	for(int i = 0 ; i <= W ; i++)
		t[0][i] = 0 ;

	for(int j = 0 ; j <= n ; j++)
		t[j][0] = 1 ;

	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= W ; j++)
		{
			if(wt[i-1] <= j)
				t[i][j] = t[i][j-wt[i-1]] + t[i-1][j] ;

			else
				t[i][j] = t[i-1][j] ;
		}
	}

	return t[n][W] ;
}

int main()
{
	vector<int> coin {1,2,3} ;
	int Sum = 4 ;

	int n ;
	n = coin.size() ;

	int count = getCount(coin, Sum, n) ;
	cout<<"The count having sum "<<Sum<<" is "<<count<<endl ;
	return 0 ;
}