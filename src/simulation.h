#ifndef SIMULATION_CLASS
#define SIMULATION_CLASS

#include <iostream>
#include <unistd.h>
#include <mutex>
#include <vector>
#include "model/SimulationData.h"
#include "model/SimulationResults.h"
#include "simulationRun.h"

class Simulation{
public:

    static std::vector<SimulationResults> simResults;

    static bool simulationV1(SimulationData simulationData, int ti);

};

#endif