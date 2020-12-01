#include "domain.h"
#include <fstream>
#include <algorithm>
#include <iostream>
using namespace std;

ifstream fin("input.in");

DirectedGraph::DirectedGraph() {
	fin >> this->numberOfVertices >> this->numberOfEdges;
	this->inEdges = this->outEdges = vector<vector<int>>(this->numberOfVertices + 1);
	this->costs = vector<cost>(this->numberOfEdges + 1);
	int x, y, w;
	for (int i = 0; i < this->numberOfEdges; i++) {
		fin >> x >> y >> w;
		this->inEdges[x].push_back(y);
		this->outEdges[y].push_back(x);
		this->costs.push_back({ {x, y}, w });
		this->largestVertex = max(x, y);
	}
	fin.close();
}

int DirectedGraph::getNumberOfVertices() {
	return this->numberOfVertices;
}

void DirectedGraph::parseTheVertices() {
	for (int i = 0; i <= this->numberOfVertices; i++) {
		for (int j : this->inEdges[i])
			cout << "Edge from " << j << " to " << i << "\n";
	}
}

bool DirectedGraph::findEdge(int firstVertex, int secondVertex) {
	bool cnt = false;
	if (this->inEdges[firstVertex].size() > 0) {
		for (int y : this->inEdges[firstVertex]) {
			if (y == secondVertex) {
				cnt = true;
				break;
			}
		}
	}
	return cnt;
}

void DirectedGraph::getInDegreeOutDegree(int vertex) {
	cout << "In degree is " << this->inEdges[vertex].size() << " and out degree is " << this->outEdges[vertex].size();
}

void DirectedGraph::parseOutboundEdges(int vertex) {
	for (int y : this->outEdges[vertex]) {
		cout << y << " ";
	}
}

void DirectedGraph::parseInboundEdges(int vertex) {
	for (int y : this->inEdges[vertex]) {
		cout << y << " ";
	}
}

void DirectedGraph::retrieveModifyInformation(int firstVertex, int secondVertex, int information) {
	for (cost info : this->costs) {
		if (info.first.first == firstVertex && info.first.second == secondVertex) {
			cout << "Initial cost was " << info.second;
			info.second = information;
			break;
		}
	}
}

void DirectedGraph::addEdge(int firstVertex, int secondVertex, int cost) {
	if (max(secondVertex, firstVertex) > this->largestVertex)
	{
		this->largestVertex = max(secondVertex, firstVertex);
		this->inEdges.resize(this->largestVertex + 1);
		this->outEdges.resize(this->largestVertex + 1);
		this->numberOfVertices++;
		this->numberOfEdges++;
		this->costs.resize(this->numberOfEdges);
	}
	this->inEdges[firstVertex].push_back(secondVertex);
	this->outEdges[secondVertex].push_back(firstVertex);
	this->costs.push_back({ {firstVertex, secondVertex}, cost });
}

void DirectedGraph::removeVertex(int vertex) {
	vector<cost>::iterator itCost;
	vector<int>::iterator it;
	vector<vector<int>>::iterator newIt;
	//erase the in edges
	it = this->inEdges[vertex].begin();
	int aux = 0;
	itCost = this->costs.begin();
	newIt = this->inEdges.begin();
	int index = 0;
	for (int y : this->inEdges[vertex]) {
		aux += index;
		//it += index;
		//this->inEdges[vertex].erase(this->inEdges[vertex].begin());
		int i = 0;
		aux -= index;
		for (int x : this->outEdges[y]) {
			//it -= index;
			//it += i;
			aux += i;
			this->outEdges[y].erase(this->outEdges[y].begin() );
			aux -= i;
			i++;
			//it -= i;
		}
		this->inEdges[vertex].erase(this->inEdges[vertex].begin());

		index++;
	}
	it -= index;
	newIt += vertex;
	this->inEdges.erase(newIt);
	
	//erase the out edges
	it = this->outEdges[vertex].begin();
	newIt = this->outEdges.begin();
	index = 0;
	for (int y : this->outEdges[vertex]) {
		it += index;
		this->outEdges[vertex].erase(it);
		int i = 0;
		for (int x : this->inEdges[y]) {
			it -= index;
			it += i;
			this->inEdges[y].erase(it);
			i++;
			it -= i;
		}
		index++;
	}
	it -= index;
	newIt += vertex;
	this->outEdges.erase(newIt);
	
	//erase the costs
	index = 0;
	for (cost info : this->costs) {
		if (info.first.first == vertex || info.first.second == vertex) {
			itCost += index;
			this->costs.erase(itCost);
			itCost -= index;
		}
	}
	/*
	for (cost info : this->costs) {
		if (info.first.first == firstVertex && info.first.second == secondVertex) {
			it = this->costs.begin();
			it += index;
			this->costs.erase(it);
		}
		index++;
	}*/
}
/*
void addVertex(int vertex) {

}*/
void DirectedGraph::removeEdge(int firstVertex, int secondVertex) {
	vector<cost>::iterator itCost;
	int index = 0;
	itCost = this->costs.begin();
	for (cost info : this->costs) {
		if (info.first.first == firstVertex && info.first.second == secondVertex) {
			itCost += index;
			this->costs.erase(itCost);
		}
		index++;
	}
}
DirectedGraph DirectedGraph::copyGraph() {
	return *this;
}

//~DirectedGraph();