#include<iostream>
#include<bits/stdc++.h>
#include<list>

using namespace std ;

class Graph{
	private :
	int V ;
	list<int>* adj ;

	public :
	Graph(int V) ;
	void addEdge(int v, int w) ;
	void shortestPath(int v) ;
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

void Graph :: shortestPath(int v)
{
	bool* visited = new bool[V] ;
	for(int i = 0 ; i < V ; i++)
		visited[i] = false ;

	int* dist = new int[V] ;
	for(int i = 0 ; i < V ; i++)
		dist[i] = INT_MAX ;


	queue<int> q ;
	q.push(v) ;
	visited[v] = true ;
	dist[v] = 0 ;

	while(!q.empty())
	{
		int curr = q.front() ;
        q.pop();
		list<int>::iterator i ;
		for(i = adj[curr].begin() ; i != adj[curr].end() ; i++)
		{
			if(dist[curr] + 1 < dist[*i])
			{
				q.push(*i) ;
				dist[*i] = dist[curr] + 1 ;
			}
		}
	}

	for(int i = 0 ; i < V ; i++)
		cout<<"Distance of "<<i<<" from "<<v<<" is "<<dist[i]<<endl ;

}

int main()
{
	Graph g(9);
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 6);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(7, 8);
 
    cout << "Following is shortest path from 0 "<<endl ;
    g.shortestPath(0);
 
    return 0;
}