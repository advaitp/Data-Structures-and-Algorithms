#include<iostream>
#include<bits/stdc++.h>
#include<list>

using namespace std ;

class Graph{
	private :
	int V ;
	list<int>* adj ;
	bool* visited ;
	stack<int> st ;
	void DFS(int i) ;

	public :
	Graph(int V) ;
	void addEdge(int v, int w) ;
	void topologicalsort() ;
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
}

void Graph :: topologicalsort()
{
	visited = new bool[V] ;
	for(int i = 0 ; i < V ; i++)
	{
		visited[i] = false ;
	}

	for(int i = 0 ; i < V ; i++)
	{
		if(!visited[i])
		{
			DFS(i) ;
		}
	}

	while(!st.empty())
	{
		int curr = st.top() ;
		st.pop() ;
		cout<<curr<<" " ;
	}
	cout<<endl ;
}

void Graph :: DFS(int v)
{
	visited[v] = true ;
	list<int>::iterator i ;
	for(i = adj[v].begin() ; i != adj[v].end() ; i++)
	{
		if(!visited[*i])
			DFS(*i) ;
	}

	st.push(v) ;
}

int main()
{
	Graph g(6);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(5, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 1);
    g.addEdge(4, 1);
 
    cout << "Following is Topological Sort " <<endl ;
    g.topologicalsort();
 
    return 0;
}