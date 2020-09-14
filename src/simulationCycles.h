#ifndef SIMULATIONCYCLES_CLASS
#define SIMULATIONCYCLES_CLASS

#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>
#include <random>
#include <map>
#include <algorithm>
#include "model/GsopNode.h"

class SimulationCycles{

public:
    static bool cycleV1(std::unordered_map<int,GsopNode> *nodes, SimulationData simulationData, std::mt19937 *eng, std::string *behaviorSnapshot);
};

#endif
