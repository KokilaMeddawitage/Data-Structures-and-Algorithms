#include <iostream>
using namespace std;
#include <limits.h>

#define V 6 //no. of vertices

//function to get the minimum time spent
int minimum_Time(int time[], bool sptSet[]){
    int min = INT_MAX, min_index;

	for (int vrtx = 0; vrtx < V; vrtx++)
		if (sptSet[vrtx] == false && time[vrtx] <= min)
			min = time[vrtx], min_index = vrtx;

	return min_index;
}


int source_vertx=0;    //a variable to store the source index 
//function to print the solution
void printSolution(int time[]){
    float sum=0;    //variable to calculate total time taken to traverse to all cities from one city
    for (int i = 0; i < V; i++){
        cout << "Shortest time from city "<< source_vertx << " to city "<<i<<" -> : "<<time[i]<<endl;
        sum=sum+time[i];
    }
    source_vertx++;
    cout << "Average time taken= "<< sum/5 << endl;
    cout << " " <<endl;
}
//adjacency matrix
int sum=0;
void dijkstra(int graph[V][V], int source){
	int time[V]; //array of storing times
	bool sptSet[V]; //boolean array to find whether vertices are considered or not
	for (int i = 0; i < V; i++)
		time[i] = INT_MAX, sptSet[i] = false;
	// Time taken to travel from source vertex to itself
	time[source] = 0;

	// shortest time taken for all vertices
	for (int count = 0; count < V - 1; count++) { //get the vertex with minimum time taken
		int u = minimum_Time(time, sptSet);
		sptSet[u] = true;

	
		for (int v = 0; v < V; v++)
    //calculating the total time taken and shortest paths
			if (!sptSet[v] && graph[u][v] && time[u] != INT_MAX
				&& time[u] + graph[u][v] < time[v]){
				time[v] = time[u] + graph[u][v];
			}
			
	}
	// print times taken
	printSolution(time);
}
int main(){
    //adjacency matrix for the given scenario
	int graph[V][V] = { { 0,10,0,0,15,5},
						{ 10,0,10,30,0,0},
						{ 0,10,0,12,5,0},
						{ 0,30,12,0,0,20},
						{ 15,0,5,0,0,0},
						{ 5,0,0,20,0,0}};

	// Function call 6 times for six cities
	for (int i=0;i<V;i++){
	    dijkstra(graph, i);
	}
	return 0;
}
