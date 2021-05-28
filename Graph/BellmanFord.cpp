#include<iostream>
#include<bits/stdc++.h>
#include<list>

// BELLMAN FORD O(V*E) 
// TIME COMPLEX O(N)

using namespace std ;

class Edge
{
	public : 
	int src ;
	int end ;
	int weight ;

	Edge(int u, int v, int w)
	{
		src = u ;
		end = v ; 
		weight = w ;
	}
} ;

class Graph{
	private :
	int V ;
	vector<Edge> edges ;

	public :
	Graph(int V) ;
	void addEdge(int v, int w, int weight) ;
	void BellmanFord(int v) ;
} ;

Graph :: Graph(int V) 
{
	this->V = V ;
	// adj = new vector<pair<int,int>>(V+1) ;
}

void Graph :: addEdge(int v, int w, int weight)
{
	Edge edge(v, w, weight) ;
	edges.push_back(edge) ;
}

void Graph :: BellmanFord(int v)
{
	vector<int> dist(V,INT_MAX); 	

	dist[v] = 0 ;
	for(int i = 1 ; i <= V-1 ; i++)
	{
		for(auto edge : edges)
		{
			// cout<<edge.src<<endl ;
			if(dist[edge.src] + edge.weight < dist[edge.end])
			{
				dist[edge.end] = dist[edge.src] + edge.weight ;
			}
		}
	}

	int f1 = 0 ;
	for(auto edge : edges)
	{
		if(dist[edge.src] + edge.weight < dist[edge.end])
		{
			cout<<"Negative Cycle"<<endl ;
			f1 = 1 ;
			break ;
		}
	}

	if(!f1)
	{
		for(int i = 0 ; i < V ; i++)
			cout<<"Distance of "<<i<<" from "<<v<<" is "<<dist[i]<<endl ;
	}

}

int main()
{
	Graph g(5);
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(1, 4, 2);
    g.addEdge(3, 2, 5);
    g.addEdge(1, 1, 1);
    g.addEdge(4, 3, -3);

    // g.addEdge(0, 1, 1);
    // g.addEdge(0, 3, 1);
    // g.addEdge(1, 2, 1);
    // g.addEdge(2, 6, 1);
    // g.addEdge(3, 4, 1);
    // g.addEdge(4, 5, 1);
    // g.addEdge(5, 6, 1);
    // g.addEdge(6, 7, 1);
    // g.addEdge(7, 8, 1);
 
    
    cout << "Following is shortest path from 0 "<<endl ;
    g.BellmanFord(0);
 
    return 0;
}