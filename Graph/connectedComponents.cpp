#include<iostream>
#include<bits/stdc++.h>
#include<list>

using namespace std ;

class Graph{
	private :
	int V ;
	list<int>* adj ;
	void DFSUtil(int i, bool visited[]) ;

	public :
		Graph(int V) ;
		void addEdge(int v, int w) ;
		void connectedComponents() ;
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

void Graph :: connectedComponents()
{
	bool* visited = new bool[V] ;
	for(int i = 0 ; i < V ; i++)
		visited[i] = false ;

	for(int i = 0 ; i < V ; i++)
	{
		if(!visited[i])
		{
			DFSUtil(i, visited) ;
			cout<<endl ;
		}
	}
}

void Graph :: DFSUtil(int v, bool visited[])
{
	visited[v] = true ;
	cout<<v<<" " ;
	list<int>::iterator i ;
	for(i = adj[v].begin(); i != adj[v].end() ; i++)
	{
		if(!visited[*i])
			DFSUtil(*i, visited) ;
	}

}

int main()
{
	Graph g(5) ;
	g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    cout<<"Connected Components are "<<endl ;
	g.connectedComponents() ;

	return 0 ;
}