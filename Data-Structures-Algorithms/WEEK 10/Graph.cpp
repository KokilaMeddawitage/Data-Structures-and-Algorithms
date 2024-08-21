#include <iostream>
#include <list>
using namespace std;

struct Node {
    int label;  //1. data type int called label
    list<int> neighbours;   //2. a int type list called neighbours
};

struct Graph {
    //graph will have an array of type "node" with length specified by n
    int n = 9;
    Node * nodes = new Node[n];

    void initializeNodes() {
        //iterate through the nodes and assign labels
        for (int i = 1; i < n; i++) {
            nodes[i].label = i;
        }
    }

    void addEdge(int u, int v) {
        //select node u and push v into u's neighbour
        nodes[u].neighbours.push_back(v);
        //select node v and push u into v's neighbour
        nodes[v].neighbours.push_back(u);  
    }

    void print() {
        //lets iterate through each node and print its neighbours
        for (int i = 1; i < n; i++) {
            cout << nodes[i].label << " --> ";
            for (int neighbour : nodes[i].neighbours) {
                cout << neighbour << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph* g = new Graph;
    g->initializeNodes();

    // Add edges for the graph
    
    //neighbours of node 1
    g->addEdge(2,1);    
    g->addEdge(3,1);
    g->addEdge(4,1);
    g->addEdge(5,1);
    
    //g->addEdge(2,1);
    //neighbours of node 2
    g->addEdge(3,2);
    g->addEdge(6,2);
    
    //neighbours around node 4
    g->addEdge(6,4);
    g->addEdge(7,4);
    g->addEdge(8,4);
    
    //g->addEdge(1,5);
    g->addEdge(6,5);
    g->addEdge(7,5);
    g->addEdge(8,5);
    
    // Print the graph adjacency list
    g->print();

    delete g;  // Deallocate memory

    return 0;
}
