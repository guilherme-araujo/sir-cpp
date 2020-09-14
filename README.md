# SIR C++ Simulator

This project aims to implement a simple SIR (Susceptible-Infected-Recovered) simulator of infected disease spread.

Initially, the script at dist/main.py is able to create a random graph, which is then loaded by the C++ program to run the simulation.

Example of generation of the initial graph:

    python3 main.py --operation=newGraph --graphtype=ba --numNodes=2000 --numEdges=1

This will generate a random Barabasi-Albert graph with 2000 nodes.

Then, build the simulation binary with

    make

at the project root. A binary named sircppsim will be generated at the dist/ folder.