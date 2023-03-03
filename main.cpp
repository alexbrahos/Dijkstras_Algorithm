#include <iostream>
#include <limits>

struct Node {
	//Default distance is infinity
	double minDist = std::numeric_limits<double>::infinity();
	bool visited = false;
};

int main() {

	//Array of all Nodes
	Node allNodes[16];

	//Initial node is already visited and its distance is always 0
	allNodes[0].minDist = 0;
	allNodes[0].visited = true;

	//Initialize adjacency matrix and manually input distances
	double adj[16][16];

	//All entries are infinity except for diagonal which is all 0
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			adj[i][j] = std::numeric_limits<double>::infinity();
			if (i == j) {
				adj[i][j] = 0;
			} //end if
		} //end inside for
	} //end outside for

	//Fill adjacency matrix
	adj[0][1] = 0.32;
	adj[0][2] = 0.4;
	adj[1][0] = 0.32;
	adj[1][4] = 0.4;
	adj[2][0] = 0.4;
	adj[2][3] = 0.1;
	adj[2][5] = 0.2;
	adj[3][2] = 0.1;
	adj[3][4] = 0.08;
	adj[3][6] = 0.2;
	adj[4][1] = 0.4;
	adj[4][3] = 0.08;
	adj[4][7] = 0.2;
	adj[5][2] = 0.2;
	adj[5][6] = 0.1;
	adj[5][8] = 0.28;
	adj[6][3] = 0.2;
	adj[6][5] = 0.1;
	adj[6][7] = 0.05;
	adj[6][8] = 0.15;
	adj[7][4] = 0.2;
	adj[7][6] = 0.05;
	adj[7][9] = 0.35;
	adj[8][5] = 0.28;
	adj[8][6] = 0.15;
	adj[8][9] = 0.25;
	adj[9][7] = 0.35;
	adj[9][8] = 0.25;
	adj[9][10] = 0.2;
	adj[9][11] = 0.3;
	adj[9][12] = 0.3;
	adj[10][9] = 0.2;
	adj[10][11] = 0.2;
	adj[11][9] = 0.3;
	adj[11][10] = 0.2;
	adj[11][13] = 0.05;
	adj[11][14] = 0.28;
	adj[12][9] = 0.3;
	adj[12][13] = 0.45;
	adj[13][11] = 0.05;
	adj[13][12] = 0.45;
	adj[13][15] = 0.3;
	adj[14][11] = 0.28;
	adj[14][15] = 0.2;
	adj[15][13] = 0.3;
	adj[15][14] = 0.2;


	//find shortest distance to node 15
	double currMin;
	int sNode;
	while (!allNodes[15].visited) {
		
		currMin = std::numeric_limits<double>::infinity();
		sNode = -1;
		for (int i = 0; i < 16; i++) {

			if (allNodes[i].visited) {

				for (int j = 0; j < 16; j++) {

					if (!allNodes[j].visited) {

						if (allNodes[i].minDist + adj[i][j] < currMin) { //Select the smallest distance between a visited and unvisited node

							currMin = allNodes[i].minDist + adj[i][j];
							sNode = j;

						} //end if smaller

					} //end if not visited

				} //end for -- goes through each column of a row

			} //end if visited

		} //end for -- Next shortest distance has been found

		allNodes[sNode].minDist = currMin;
		allNodes[sNode].visited = true;

	} //end while -- Node 15 has been visited

	std::cout << "Shortest distance to node 15 (Point B in assignment image) is " << allNodes[15].minDist << std::endl;
}
