#include <bits/stdc++.h>
using namespace std;

// No of vertices
#define V 6
//function to find vertices with minimum key values
int minKey(int key[], bool mstSet[])
{
	// Initialize min value to a variable
	int minimum = INT_MAX, min_index;

	for (int vrtx = 0; vrtx < V; vrtx++)
		if (mstSet[vrtx] == false && key[vrtx] < minimum)
			minimum = key[vrtx], min_index = vrtx;

	return min_index;
}

//function to print the MST
void printMST(int parent[], int graph[V][V])
{
	cout << "Edge \tWeight\n";
	for (int j = 1; j < V; j++)
		cout << parent[j] << " - " << j << " \t"
			<< graph[j][parent[j]] << " \n";
}

//function to print MST
void primMST(int graph[V][V])
{
	// parent Array stores MST
	int parent[V];

	// keep minimum key values
	int key[V];

	// bool array to store vertices
	bool mstSet[V];

	for (int i = 0; i < V; i++)
		key[i] = INT_MAX, mstSet[i] = false;

	//keep source vertex as 0
	key[0] = 0;
	parent[0] = -1;

	// iterate through MST
	for (int c = 0; c < V - 1; c++) {
		
		//get the minimum vertex that is not in MST
		int u = minKey(key, mstSet);

		// append the above min value to the set
		mstSet[u] = true;

		for (int v = 0; v < V; v++)
			if (graph[u][v] && mstSet[v] == false
				&& graph[u][v] < key[v])
				parent[v] = u, key[v] = graph[u][v];
	}

	// Printing MST
	printMST(parent, graph);
}

int main()
{
	int graph[V][V] = { { 0,3,0,0,0,1 },
						{ 3,0,2,1,10,0},
						{ 0,2,0,3,0,5 },
						{ 0,1,3,0,5,0 },
						{ 0,10,0,5,0,4},
						{ 1,0,5,0,4,0 } };

	// Print the solution
	primMST(graph);

	return 0;
}

