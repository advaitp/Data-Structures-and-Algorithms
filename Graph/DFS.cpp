#include<iostream>
#include<bits/stdc++.h>
#include<list>

using namespace std ;

class Graph{
	private :
	int V ;
	list<int>* adj ;
	bool* visited ;

	public :
	Graph(int V) ;
	void addEdge(int v, int w) ;
	void DFS(int v) ;
} ;

Graph :: Graph(int V) 
{
	this->V = V ;
	adj = new list<int>[V] ;

	visited = new bool[V] ;
	for(int i = 0 ; i < V ; i++)
	{
		visited[i] = false ;
	}
}

void Graph :: addEdge(int v, int w)
{
	adj[v].push_back(w) ;
	adj[w].push_back(v) ;
}

void Graph :: DFS(int v)
{
	visited[v] = true ;
	cout<<v<<" " ;
	list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFS(*i) ;
}

int main()
{
	Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(4, 3);
 
    cout << "Following is Depth First Traversal " << "(starting from vertex 2) \n";
    g.DFS(2);
 
    return 0;
}