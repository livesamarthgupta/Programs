#include<bits/stdc++.h>
using namespace std;

/*
	Graph implementation as Adjacency List with following functions:
	void addVertex(int node);
	void addEdge(int node1, int node2);
	void print();
*/

class Graph
{
private:
	unordered_map<int, vector<int>> graph;
	int size;
	
public:
	Graph()
	{
		size = 0;
	}
	
	void addVertex(int node)
	{
		size++;
	}
	
	void addEdge(int node1, int node2)
	{
		graph[node1].push_back(node2);
		graph[node2].push_back(node1);
	}
	
	void print()
	{
		for(auto i = graph.begin(); i != graph.end(); i++)
		{
			cout<<i->first<<" --> ";
			for(auto j = 0; j < i->second.size(); j++)
			{
				cout<<i->second[j]<<" ";
			}
			cout<<endl;
		}
	}
};

int main()
{
	Graph g;
	g.addVertex(1);
	g.addVertex(2);
	g.addVertex(3);
	g.addEdge(1, 2);
	g.addEdge(2, 3);
	g.print();
}
