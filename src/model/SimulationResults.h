#ifndef MODEL_SIMULATIONRESULTS
#define MODEL_SIMULATIONRESULTS

#include <vector>
#include "GsopNode.h"

class SimulationResults{

	public:

	std::vector<int> typeAPopHistory;
	std::vector<GsopNode> finalNodes;
	double elapsedSeconds;
	int fixationCycles;
	std::string stateHistoryStr;

};

#endif