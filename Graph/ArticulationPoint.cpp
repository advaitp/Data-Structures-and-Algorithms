#include<iostream>
#include<bits/stdc++.h>
#include<list>

using namespace std ;

class Graph{
	private :
	int V ;
	int timer ;
	list<int>* adj ;
	bool* visited ;
	int* in ;
	int* low ;

	public :
	Graph(int V) ;
	void addEdge(int v, int w) ;
	void DFS(int node, int par) ;
} ;

Graph :: Graph(int V) 
{
	this->V = V ;
	adj = new list<int>[V] ;

	visited = new bool[V] ;
	in = new int[V] ;
	low = new int[V] ;
	for(int i = 0 ; i < V ; i++)
	{
		visited[i] = false ;
		low[i] = i ;
		in[i] = i ;
	}

	timer = 0 ;
}

void Graph :: addEdge(int v, int w)
{
	adj[v].push_back(w) ;
	adj[w].push_back(v) ;
}

void Graph :: DFS(int node, int par)
{
	visited[node] = 1 ;
	in[node] = low[node] = timer ;
	timer++ ;
	int children = 0 ;
	for(auto child : adj[node])
	{
		if(child == par) continue ;
		if(visited[child])
			low[node] = min(low[node], in[child]) ;

		else
		{
			DFS(child, node) ;
			children++ ;
			low[node] = min(low[node], low[child]) ;
			if(low[child] > in[node] && par != -1)
				cout<<node<<" is a articulation point"<<endl ;
			
		}

		if(par == -1 && children > 1)
			cout<<node<<" is a articulation point"<<endl ;
	}
}

int main()
{
	Graph g(12);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(4, 3);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(5, 8);
    g.addEdge(7, 6);
    g.addEdge(7, 8);
    g.addEdge(7, 9);
    g.addEdge(9, 10);
    g.addEdge(9, 11);
    g.addEdge(11, 10);
 
    g.DFS(0, -1);
 
    return 0;
}