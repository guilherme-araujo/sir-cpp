#include "simulation.h"

std::mutex out;

using namespace std;

bool Simulation::simulationV1(SimulationData simulationData, int ti){


	SimulationResults simulationResults = SimulationRun::runSimV1(simulationData, ti);

	out.lock();
	if(simulationData.stateHistory){
		cout<<simulationResults.stateHistoryStr;
	}
	
	if(simulationData.printPartials){
		for(unsigned int i = 500; i <= simulationResults.typeAPopHistory.size(); i+=500){
			cout<<"partial;"<<i<<";"<<simulationResults.typeAPopHistory[i-1]<<";"<<simulationData.sampleid<<endl;
		}
	}

	int fc = simulationResults.fixationCycles;
	int numCycles = simulationResults.typeAPopHistory.size()-1;
	cout<<simulationResults.typeAPopHistory[numCycles]<<";"<<fc<<";"<<simulationResults.elapsedSeconds<<";"<<simulationData.sampleid<<endl;


	out.unlock();

	return true;
}

vector<SimulationResults> Simulation::simResults;
