#ifndef SIMULATIONRUN_CLASS
#define SIMULATIONRUN_CLASS

#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <random>
#include <chrono>
#include <functional>
#include "simulationCycles.h"
#include "model/Graph.h"
#include "model/SimulationData.h"
#include "model/SimulationResults.h"


class SimulationRun{

public:

	static SimulationResults runSimV1(SimulationData simulationData, int ti);
};

#endif
