#include<iostream>
#include<bits/stdc++.h>
#include<vector>

using namespace std ;
static int t[5][24] ;

vector<int> knapSack(vector<int>& wt, int n, int W)
{
	vector<int> subsets ;
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

	for(int j = 0 ; j <= W ; j++)
	{
		if(t[n][j]) subsets.push_back(j) ;
	}

	return subsets ;
}

int getMindiff(vector<int>& arr)
{
	int Range = 0 ;
	for(int ele : arr)
		Range += ele ;
	int n = arr.size() ;

	vector<int> subsets = knapSack(arr, n, Range) ;
	int finalDiff = INT_MAX ;
	for(int ele : subsets)
	{
		if((Range - 2*ele) > 0)
		{
			finalDiff = min(finalDiff, (Range - 2*ele)) ;
		}
	}
	return finalDiff ;
}

int main()
{
	std::vector<int> arr {1, 5, 11, 6} ;
	int diff = getMindiff(arr) ;
	cout<<"Min difference between 2 subsets is "<<diff<<endl ;
	return 0 ;
}