#include<iostream>
#include<bits/stdc++.h>
#include<list>

// TIME COMPLEX O(nlogn)
// SPACE COMPLEX O(n)

using namespace std ;

class Edge
{
	public : 
	int src ;
	int end ;
	int weight ;

	Edge(int u, int v, int w)
	{
		src = u ;
		end = v ; 
		weight = w ;
	}
} ;

class UnionFind{
	private : 
	int V ;
	int* Parent ;
	int components ;

	public :
	UnionFind(int V)
	{
		this->V = V ;
		Parent = new int[V] ;
		components = 0 ;
		for(int i = 0 ; i < V ; i++)
			Parent[i] = i ;
	}

	int Find(int v)
	{
		if(v == Parent[v])
			return v ;
		else
			return Find(Parent[v]) ;
	}

	void Union(int u, int v)
	{
		int pu = Find(u) ;
		int pv = Find(v) ;

		if(pu != pv)
		{
			Parent[pu] = pv ;
		} 
	}
} ;

class Graph{
	private :
	int V ;
	vector<Edge> edges ;
	static bool comp(Edge a, Edge b)
	{
		return a.weight < b.weight ;
	}

	public :
	Graph(int V) ;
	void addEdge(int v, int w, int weight) ;
	void Kruskal() ;
} ;

Graph :: Graph(int V) 
{
	this->V = V ;
}

void Graph :: addEdge(int v, int w, int weight)
{
	Edge edge(v, w, weight) ;
	edges.push_back(edge) ;
}

void Graph :: Kruskal()
{
	sort(edges.begin(), edges.end(), comp) ;
	UnionFind uf(V) ;
	int count = 0 ;

	for(auto edge : edges) 
	{
		if(count > V-1) break ;
		if(uf.Find(edge.src) != uf.Find(edge.end))
		{
			uf.Union(edge.src, edge.end) ;
			cout<<edge.src<<" "<<edge.end<<" "<<edge.weight<<endl ;
		}
	}
}


int main()
{
	
    Graph g(6);
    g.addEdge(0, 1, 2);
    g.addEdge(0, 3, 1);
    g.addEdge(0, 4, 4);
    g.addEdge(1, 3, 3);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 4, 5);
    g.addEdge(1, 5, 7);
    g.addEdge(2, 5, 8);
    g.addEdge(4, 3, 9);
 
    
    cout <<"MST using Kruskal Algo is"<<endl ;
    g.Kruskal();
 
    return 0;
}