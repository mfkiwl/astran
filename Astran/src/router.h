/***************************************************************************
*   Copyright (C) 2005 by Adriel Mota Ziesemer Jr., Cristiano Lazzari     *
*   (amziesemerj,clazz)@inf.ufrgs.br                                      *
***************************************************************************/
#ifndef ROUTER_H
#define ROUTER_H

/**
Route the graph using a Pathfinder based algorithm

@author Adriel Mota Ziesemer Jr.
*/

#include <vector>
#include <list>
#include <queue>
#include <iostream>
#include <strstream>
#include <fstream>

#include <time.h>


#include <wx/process.h>
#include "circuit.h"
#include "pathfinder.h"
#include "compaction.h"

using namespace std;

class Router{
	protected:
	bool teste;
	unsigned int sizeX, sizeY, sizeZ, size, pitchH, pitchV;	
	Circuit* currentCircuit;
	map<string, int> netIndex;
	Pathfinder rt;
	public:
	Router();
	~Router();
	Pathfinder* getPathfinderRt(){return &rt;};
	void test(string r);
	void setCircuit(Circuit* c){currentCircuit=c;};
	void addNodetoNet(string net, unsigned int p);
	void addNodetoNet(int net, unsigned int node);	
	unsigned int searchNet(string net);
	void setup(int sX, int sY, int sZ);
	void route(int effort);
	void optimize();
	void rotdl(string path);
	void compactLayout(string lpSolverFile);
	int getNrNets(int x, int y, int z);
	void saveRoutingRotdl(string fileName);
	void readRoutingRotdl(string fileName);
};

#endif

