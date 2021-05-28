#include<iostream>
#include<bits/stdc++.h>
#include<list>

// TIME COMPLEX O(nlogn)
// SPACE COMPLEX O(n) 
using namespace std ;

class Graph{
	private :
	int V ;
	vector<pair<int,int>> adj[6] ;
	int* key ;
	bool* mst ;
	int* parent ;

	public :
	Graph(int V) ;
	void addEdge(int v, int w, int weight) ;
	void Prim() ;
} ;

Graph :: Graph(int V) 
{
	this->V = V ;
	// adj = new list<int>[V] ;
}

void Graph :: addEdge(int v, int w, int weight)
{
	adj[v].push_back({w, weight}) ;
	adj[w].push_back({v, weight}) ;
}

void Graph :: Prim()
{
	key = new int[V] ;
	mst = new bool[V] ;
	parent = new int[V] ;

	for(int i = 0 ; i < V ; i++)
	{
		key[i] = INT_MAX ;
		mst[i] = false ;
		parent[i] = -1 ;
	}

	key[0] = 0 ;

	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // MINHEAP
	pq.push({key[0], 0}) ;
	for(int count = 0 ; count < V-1 ; count++)
	{
		int node = pq.top().second ;
		int parentweight = pq.top().first ;

		pq.pop() ;
		vector<pair<int,int>>::iterator it ;
		mst[node] = true ;

		for(it = adj[node].begin() ; it != adj[node].end() ; it++)
		{
			int child = it->first ;
			int childweight = it->second ;

			if(!mst[child] && childweight < key[child])
			{
				parent[child] = node ;
				key[child] = childweight ;
				pq.push({key[child], child}) ;
			}
		}
	}

	cout<<"The Minimum Spanning Tree "<<endl ;
	for(int i = 1 ; i < V ; i++)
		cout<<parent[i]<<"->"<<i<<" "<<key[i]<<endl ;
}


int main()
{
	Graph g(6);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 1);
    g.addEdge(0, 4, 4);
    g.addEdge(1, 3, 3);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 4, 5);
    g.addEdge(1, 5, 7);
    g.addEdge(2, 5, 8);
    g.addEdge(4, 3, 9);
 
    cout <<"MST using Prim Algo is"<<endl ;
    g.Prim();
 
    return 0;
}