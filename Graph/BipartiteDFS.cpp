#include<iostream>
#include<bits/stdc++.h>
#include<list>

using namespace std ;
// BIPARTITE USING DFS

class Graph{
	private :
	int V ;
	list<int>* adj ;
	bool dfsCheck(int color[], int v) ;

	public :
	Graph(int V) ;
	void addEdge(int v, int w) ;
	bool isBipartite() ;
} ;

Graph :: Graph(int V) 
{
	this->V = V ;
	adj = new list<int>[V] ;
}

void Graph :: addEdge(int v, int w)
{
	adj[v].push_back(w) ;
	adj[w].push_back(v) ;
}

bool Graph :: isBipartite()
{
	int* color = new int[V] ;
	for(int i = 0 ; i < V ; i++)
		color[i] = -1 ;

	for(int i = 0 ; i < V ; i++)
	{
		if(color[i] == -1)
		{
			if(dfsCheck(color, i))
				return true ;
		}
	}

	return false ;
}

bool Graph :: dfsCheck(int color[], int v)
{
	if(color[v] == -1) color[v] = 1 ;
	list<int>::iterator i ;
	for(i = adj[v].begin() ; i != adj[v].end() ; i++)
	{
		if(color[*i] == -1)
		{
			color[*i] = 1 - color[v] ;
			if(!dfsCheck(color, *i))
				return false ;
		}

		else if(color[*i] == color[v]) 
			return false ;
	}

	return true ;

}

int main()
{
	Graph g(8) ;
	g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 5);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 6);
    g.addEdge(6, 7);
    g.addEdge(5, 4);
 
    if(g.isBipartite()) 
    	cout<<"Graph is Bipartite"<<endl ;
    else 
    	cout<<"Graph is not Bipartite"<<endl ;
 
    return 0;
}