#pragma once
#include <vector>
#include <iostream>
using namespace std;

using PII = pair<int, int>;
using cost = pair<PII, int>;

class DirectedGraph {
private:
	vector<vector<int>>inEdges;
	vector<vector<int>>outEdges;
	vector<cost>costs;
	int numberOfVertices;
	int numberOfEdges;
	int largestVertex;

public:
	DirectedGraph();
	int getNumberOfVertices();
	void parseTheVertices();
	bool findEdge(int firstVertex, int secondVertex);
	void getInDegreeOutDegree(int vertex);
	void parseOutboundEdges(int vertex);
	void parseInboundEdges(int vertex);
	void retrieveModifyInformation(int firstVertex, int secondVertex, int information);
	void addEdge(int firstVertex, int secondVertex, int cost);
	void removeEdge(int firstVertex, int secondVertex);
	//void addVertex(int vertex);
	void removeVertex(int vertex);
	DirectedGraph copyGraph();
	//~DirectedGraph();
};