#include<iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std ;

static int t[6][12] ;

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

int main()
{
	vector<int> wt {2, 3, 7, 8, 10} ;
	int n, Sum ; 
	
	n = wt.size() ;
	Sum = 11 ;

	bool isPossible = knapSack(wt, Sum, n) ;

	if(isPossible)
		cout<<"Subset possible "<<endl ;
	else 
		cout<<"Subset not possible "<<endl ;

	return 0 ;
}