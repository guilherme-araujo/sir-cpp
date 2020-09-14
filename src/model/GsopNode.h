#ifndef MODEL_GSOPNODE
#define MODEL_GSOPNODE

#include <string>
#include <vector>

#include "Eph.h"
#include "SimulationData.h"

enum NodeState{
  SUSCEPTIBLE,    //Susceptible to infection
  INFECTED,    //Infected - active disease
  RECOVERED   // Recovered, disease no longer active and cannot become infected again

};

class GsopNode{
public:

    std::string hash;
    char type;
    int id;
    int stateTimer;
    NodeState state;

    std::vector<int> neighbors;

    GsopNode();
};

#endif
