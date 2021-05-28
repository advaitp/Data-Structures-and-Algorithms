#include<iostream>
#include<bits/stdc++.h>
#include<list>

// TIME COMPLEX O((N+E)log(N)) 
// SPACE COMPLEX O(N)

using namespace std ;

class Graph{
	private :
	int V ;
	vector<pair<int,int>> adj[9] ;

	public :
	Graph(int V) ;
	void addEdge(int v, int w, int weight) ;
	void shortestPath(int v) ;
} ;

Graph :: Graph(int V) 
{
	this->V = V ;
	// adj = new vector<pair<int,int>>(V+1) ;
}

void Graph :: addEdge(int v, int w, int weight)
{
	adj[v].push_back({w, weight}) ;
}

void Graph :: shortestPath(int v)
{
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq; // MINHEAP
	vector<int> dist(V+1,INT_MAX); 	

	dist[v] = 0 ;
	pq.push({0, v}) ;
	while(!pq.empty())
	{
		int prev_weight = pq.top().first ;
		int prev_node = pq.top().second ;
		pq.pop() ;

		vector<pair<int,int>>::iterator it ;
		for(it = adj[prev_node].begin() ; it != adj[prev_node].end() ; it++)
		{
			int curr_node = it->first ;
			int curr_weight = it->second ;
			if(dist[curr_node] > dist[prev_node] + curr_weight)
			{
				dist[curr_node] = dist[prev_node] + curr_weight ;
				pq.push({dist[curr_node], curr_node}) ;
			}

		}
	}

	for(int i = 0 ; i < V ; i++)
		cout<<"Distance of "<<i<<" from "<<v<<" is "<<dist[i]<<endl ;
}

int main()
{
	Graph g(9);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 6, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 7, 1);
    g.addEdge(7, 8, 1);
 
    cout << "Following is shortest path from 0 "<<endl ;
    g.shortestPath(0);
 
    return 0;
}