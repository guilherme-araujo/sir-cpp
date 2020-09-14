#include "simulationRun.h"

using namespace std;

SimulationResults SimulationRun::runSimV1(SimulationData simulationData, int ti){

	SimulationResults simulationResults;

	simulationResults.stateHistoryStr = "";
	simulationResults.fixationCycles = -1;

	vector<GsopNode> nodes = simulationData.g->nodes;
	
	random_device rd;
	array<int, std::mt19937::state_size> seed_data;
	generate_n(seed_data.data(), seed_data.size(), std::ref(rd));
	seed_seq seq(std::begin(seed_data), std::end(seed_data));
	mt19937 eng(seq);
	shuffle(nodes.begin(), nodes.end(), eng);

	unordered_map<int, GsopNode> nodesmap;

	for(unsigned int i = 1; i < nodes.size(); i++){		
		
		//Node initialization
		nodes[i].type = 'A';
		nodes[i].state = SUSCEPTIBLE;							
		nodes[i].stateTimer = -1;
		nodesmap.insert(pair<int,GsopNode>(nodes[i].id,nodes[i]));
	}

	nodes[0].type = 'A';
	nodes[0].state = INFECTED;							
	nodes[0].stateTimer = simulationData.infectedTime;
	nodesmap.insert(pair<int,GsopNode>(nodes[0].id,nodes[0]));

	//filling neighbor list to be valid both sides
	for(unsigned int i = 0; i < nodes.size(); i++){
		for(unsigned int j = 0; j < nodes[i].neighbors.size(); j++){
			nodesmap[nodes[i].neighbors[j]].neighbors.push_back(nodes[i].id);
		}
	}	

	clock_t begin = clock();

	for(int i = 0; i < simulationData.cycles; i++){
		string stateSnapshot;
		bool isOver = SimulationCycles::cycleV1(&nodesmap, simulationData, &eng, &stateSnapshot);

		int typeACount = simulationData.initialPop; //type size not changing
		
		vector<GsopNode> nodeslist;

		if(simulationData.stateHistory){
			simulationResults.stateHistoryStr += "shistory;"+to_string(ti)+";"+to_string(i)+";"+stateSnapshot;

		}

		simulationResults.typeAPopHistory.push_back(typeACount);
		
		if(isOver){
			simulationResults.fixationCycles = i;
			break;
		} 
	}	

	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	simulationResults.elapsedSeconds = elapsed_secs;

	return simulationResults;
}

