#include "graph.hpp"
#include <iostream>
#include <vector>

int main(){
    Graph g;
    g.addVertex("Boulder");
    g.addVertex("Cheyenne");
    g.addVertex("Denver");
    g.displayVerticesObj();

    g.addEdge("Boulder", "Denver");
    g.addEdge("Boulder", "Cheyenne");
    g.addEdge("Cheyenne", "Boulder");

    g.displayEdges();
    return 0;
}