#include "console.h"
#include <iostream>
using namespace std;

void printMenu() {
	cout << "\nPlease choose one of the following actions: \n";
	cout << "1.Get the number of vertices\n"
		<< "2.Parse the set of vertices\n"
		<< "3.Find edge\n"
		<< "4.Get the in degree and the out degree of a specified vertex\n"
		<< "5.Parse the set of outbound edges of a specified vertex\n"
		<< "6.Parse the set of inbound edges of a specified vertex\n"
		<< "7.Retrieve or modify the information attached to a specified edge\n"
		<< "8.Add an edge\n"
		<< "9.Remove an edge\n"
		<< "10.Remove a vertex\n"
		<< "11.Copy the graph\n"
		<< "12.Exit\n"
		<< "Please give a command: ";
}

void main() {
	DirectedGraph *graph = new(DirectedGraph);
	DirectedGraph *copy;

	int command;
	int firstVertex, secondVertex, information;
	while (true) {
		printMenu();
		cin >> command;
		if (command == 1) {
			cout << graph->getNumberOfVertices();
		}
		else {
			if (command == 2) {
				graph->parseTheVertices();
			}
			else {
				if (command == 3) {
					cin >> firstVertex >> secondVertex;
					cout << graph->findEdge(firstVertex, secondVertex);
				}
				else {
					if (command == 4) {
						cin >> firstVertex;
						graph->getInDegreeOutDegree(firstVertex);
					}
					else {
						if (command == 5) {
							cin >> firstVertex;
							graph->parseOutboundEdges(firstVertex);
						}
						else {
							if (command == 6) {
								cin >> firstVertex;
								graph->parseInboundEdges(firstVertex);
							}
							else {
								if (command == 7) {
									cin >> firstVertex >> secondVertex >> information;
									graph->retrieveModifyInformation(firstVertex, secondVertex, information);
								}
								else {
									if (command == 8) {
										cin >> firstVertex >> secondVertex >> information;
										graph->addEdge(firstVertex, secondVertex, information);
									}
									else {
										if (command == 9) {
											cin >> firstVertex >> secondVertex;
											graph->removeEdge(firstVertex, secondVertex);
										}
										else {
											if (command == 10) {
												cin >> firstVertex;
												graph->removeVertex(firstVertex);
											}
											else {
												if (command == 11)
													copy = &graph->copyGraph();
												else
													break;
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	//return 0;
}