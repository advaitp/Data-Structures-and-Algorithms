#include<iostream>
#include<bits/stdc++.h>
#include<list>

// SHORTEST PATH OF DAG USING DFS AND BFS
using namespace std ;

class Node{
	int end ;
	int weight ;
	public :

	Node(int v, int w)
	{
		end = v ;
		weight = w ;
	}

	int getEnd() {return end ;}
	int getWeight() {return weight ;}
} ;

class Graph{
	private :
	int V ;
	list<Node>* adj ;
	bool* visited ;
	stack<int> st ;
	void DFS(int i) ;

	public :
	Graph(int V) ;
	void addEdge(int v, int w, int weight) ;
	void topologicalsort() ;
	void shortestPath(int v) ;
} ;

Graph :: Graph(int V) 
{
	this->V = V ;
	adj = new list<Node>[V] ;

	visited = new bool[V] ;
	for(int i = 0 ; i < V ; i++)
	{
		visited[i] = false ;
	}
}

void Graph :: addEdge(int v, int w, int weight)
{
	Node node(w, weight) ;
	adj[v].push_back(node) ;
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

}

void Graph :: DFS(int v)
{
	visited[v] = true ;
	list<Node>::iterator i ;
	for(i = adj[v].begin() ; i != adj[v].end() ; i++)
	{
		Node node = *i ;
		if(!visited[node.getEnd()])
			DFS(node.getEnd()) ;
	}

	st.push(v) ;
}

void Graph :: shortestPath(int v)
{
	int* dist = new int[V] ;
	for(int i = 0 ; i < V ; i++)
		dist[i] = INT_MAX ;

	topologicalsort() ;

	dist[v] = 0 ;

	while(!st.empty())
	{
		int curr = st.top() ;
        st.pop();
		list<Node>::iterator i ;
		for(i = adj[curr].begin() ; i != adj[curr].end() ; i++)
		{
			Node node = *i ;
			if(dist[curr] + node.getWeight() < dist[node.getEnd()])
			{
				dist[node.getEnd()] = dist[curr] + node.getWeight() ;
			}
		}
	}

	for(int i = 0 ; i < V ; i++)
		cout<<"Distance of "<<i<<" from "<<v<<" is "<<dist[i]<<endl ;

}

int main()
{
	Graph g(9);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 3, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 6, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 7, 1);
    g.addEdge(7, 8, 1);
 
    cout << "Following is shortest path from 0 "<<endl ;
    g.shortestPath(0);
 
    return 0;
}