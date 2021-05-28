#include<iostream>
#include<bits/stdc++.h>
#include<list>

using namespace std ;
// BIPARTITE USING BFS

class Graph{
	private :
	int V ;
	list<int>* adj ;

	public :
	Graph(int V) ;
	void addEdge(int v, int w) ;
	bool isBipartite(int v) ;
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

bool Graph :: isBipartite(int v)
{
	int* color = new int[V] ;
	for(int i = 0 ; i < V ; i++)
		color[i] = -1 ;

	queue<int> q ;
	q.push(v) ;
	while(!q.empty())
	{
		int curr = q.front() ;
        q.pop();
		list<int>::iterator i ;
		for(i = adj[curr].begin() ; i != adj[curr].end() ; i++)
		{
			if(color[*i] == -1)
			{
				q.push(*i) ;
				color[*i] = 1 - color[curr] ;
			}

			else if(color[*i] == color[curr])
				return false ;
		}
	}

	return true ;
}

int main()
{
	Graph g(5) ;
	g.addEdge(1, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
 
    if(g.isBipartite(0)) 
    	cout<<"Graph is Bipartite"<<endl ;
    else 
    	cout<<"Graph is not Bipartite"<<endl ;
 
    return 0;
}