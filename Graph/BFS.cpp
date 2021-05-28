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
	void BFS(int v) ;
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

void Graph :: BFS(int v)
{
	bool* visited = new bool[V] ;
	for(int i = 0 ; i < V ; i++)
		visited[i] = false ;

	queue<int> q ;
	q.push(v) ;
	visited[v] = true ;
	while(!q.empty())
	{
		int curr = q.front() ;
		cout << curr << " ";
        q.pop();
		list<int>::iterator i ;
		for(i = adj[curr].begin() ; i != adj[curr].end() ; i++)
		{
			if(!visited[*i])
			{
				q.push(*i) ;
				visited[*i] = true ;
			}
		}
	}
}

int main()
{
	Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.BFS(2);
 
    return 0;
}