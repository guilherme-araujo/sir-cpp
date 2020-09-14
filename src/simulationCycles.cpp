#include "simulationCycles.h"

using namespace std;

bool SimulationCycles::cycleV1(unordered_map<int,GsopNode> *nodes, SimulationData simulationData, mt19937 *eng, string *stateSnapshot){
		
	//eph times update
	for(unsigned int i = 0; i < nodes->size(); i++){
		GsopNode *n = &(*nodes)[i];
		if(n->state == INFECTED){

			vector<int> neighborsList = n->neighbors;			
			
			for(unsigned int i = 0; i < neighborsList.size(); i++){
				GsopNode *neighbor = &(*nodes)[neighborsList[i]];
				if(neighbor->state == SUSCEPTIBLE){
					uniform_real_distribution<> distr(0, 1);
					double spread = distr(*eng);
					if(spread < simulationData.spreadChance){
						neighbor->state = INFECTED;
						neighbor->stateTimer = simulationData.infectedTime;
					}
				}
			}

		}
	}

	int cSusceptibleA = 0;
	int cInfectedA = 0;
	int cRecoveredA = 0;
	
	for(unsigned int i = 0; i < nodes->size(); i++){
		GsopNode *n = &(*nodes)[i];

		if(simulationData.stateHistory){
			switch(n->state){
				case SUSCEPTIBLE:
					cSusceptibleA++;
					break;
				case INFECTED:
					cInfectedA++;
					break;
				case RECOVERED:
					cRecoveredA++;
					break;				
			}
		}

		if(n->stateTimer == 1){
			if(n->state == INFECTED){
				n->state = RECOVERED;						
			}
		}else if(n->stateTimer > 1){
			n->stateTimer -= 1;
		}
	}

	if(simulationData.stateHistory){
		*stateSnapshot = to_string(cSusceptibleA)+';'+to_string(cInfectedA)+';'+to_string(cRecoveredA)+"\n";
	}

	if(cInfectedA == 0){
		return true;
	} else return false;
}
