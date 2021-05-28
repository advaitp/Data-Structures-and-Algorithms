#include<iostream>
#include<bits/stdc++.h>
#include<list>

using namespace std ;
// DETECT CYCLE FOR DIRECTED GRAPH

class Graph{
	private :
	int V ;
	list<int>* adj ;
	int* visited ;
	int* dfsvisited ;
	bool DFScheck(int v, int visited[], int dfsvisited[]) ;

	public :
	Graph(int V) ;
	void addEdge(int v, int w) ;
	bool checkCycle() ;
} ;

Graph :: Graph(int V) 
{
	this->V = V ;
	adj = new list<int>[V] ;
}

void Graph :: addEdge(int v, int w)
{
	adj[v].push_back(w) ;
}

bool Graph :: checkCycle()
{
	int* visited = new int[V] ;
	int* dfsvisited = new int[V] ;

	for(int i = 0 ; i < V ; i++)
	{
		if(!visited[i])
		{
			if(DFScheck(i, visited, dfsvisited))
				return true ;
		}
	}

	return false ;
}

bool Graph :: DFScheck(int v, int visited[], int dfsvisited[])
{
	visited[v] = 1 ;
	dfsvisited[v] = 1 ;

	list<int>:: iterator i ;
	for(i = adj[v].begin() ; i != adj[v].end() ; i++)
	{
		if(!visited[*i])
		{
			if(DFScheck(*i, visited, dfsvisited))
				return true ;

			else if(dfsvisited[*i])
				return true ;
		}
	}

	dfsvisited[v] = 0 ;

	return false ;
}

int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.checkCycle()?
       cout << "Graph contains cycle\n":
       cout << "Graph doesn't contain cycle\n";
 
    Graph g2(3);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.checkCycle()?
       cout << "Graph contains cycle\n":
       cout << "Graph doesn't contain cycle\n";
 
    return 0;
}