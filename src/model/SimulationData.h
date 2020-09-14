#ifndef MODEL_SIMULATIONDATA
#define MODEL_SIMULATIONDATA

#include <vector>
#include <string>

class GsopGraph;

class SimulationData{

	public:

	int initialPop;
	int cycles;
	bool stateHistory;
	int infectedTime;
	bool printPartials;
	double spreadChance;

	int sampleid;
	GsopGraph *g;

};

#endif