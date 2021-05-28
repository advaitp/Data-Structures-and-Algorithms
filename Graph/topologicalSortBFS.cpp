#include<iostream>
#include<bits/stdc++.h>
#include<list>

using namespace std ;

class Graph{
	private :
	int V ;
	list<int>* adj ;
	int* endegree ;

	public :
	Graph(int V) ;
	void addEdge(int v, int w) ;
	vector<int> topoSort() 
	{
		vector<int> toposort ; 

		queue<int> q ;
		for(int i = 0 ; i < V ; i++)
		{
			if(endegree[i] == 0)
				q.push(i) ;
		}

		while(!q.empty())
		{
			int curr = q.front() ;
			q.pop() ;

			toposort.push_back(curr) ;
			// cout<<curr<<endl ;

			list<int>:: iterator i ;
			for(i = adj[curr].begin() ; i != adj[curr].end() ; i++)
			{
				endegree[*i]-- ;
				if(endegree[*i] == 0)
					q.push(*i) ;
			}

		}

		return toposort ;
	}

} ;

Graph :: Graph(int V) 
{
	this->V = V ;
	adj = new list<int>[V] ;
	endegree = new int[V] ;
	for(int i = 0 ; i < V ; i++)
		endegree[i] = 0 ;
}

void Graph :: addEdge(int v, int w)
{
	adj[v].push_back(w) ;
	endegree[w]++ ;
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
    vector<int> ans = g.topoSort();
    for(int ele : ans)
    	cout<<ele<<" " ;
    cout<<endl ;
 
    return 0;
}