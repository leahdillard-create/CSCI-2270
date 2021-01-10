#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "GraphHW8.hpp"

using namespace std;

void Graph::addVertex(string name){
    bool flag = false;

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name==name){
            flag= true;
        }
    }
    if(flag == false){
        vertex *v = new vertex;
        v->name = name;
        v->distance = 0;
        vertices.push_back(v);
    }
}

void Graph::addEdge(string v1, string v2){
    for(int i = 0; i < vertices.size();i++){
        if(vertices[i]->name==v1){
            for(int j = 0; j< vertices.size();j++){
                if(vertices[j]->name == v2 && i != j){
                    adjVertex adjacentV;
                    adjacentV.v = vertices[j];
                    vertices[i]->adj.push_back(adjacentV);

                    adjVertex adjacentV2;
                    adjacentV2.v = vertices[i];
                    vertices[j]->adj.push_back(adjacentV2);
                }
            }
        }
    }
}

void Graph::displayEdges(){
    for(int i = 0; i < vertices.size();i++){
        cout << vertices[i]->name << " --> ";
        for(int j = 0; j< vertices[i]->adj.size();j++){
            cout << vertices[i]->adj[j].v->name<< " ";
        }
        cout << endl;
    }
}

void Graph::breadthFirstTraverse(string sourceVertex)
{
    vertex *v = NULL;

    for(int i = 0; i < vertices.size();i++){
        if(vertices[i]->name == sourceVertex){
            v = vertices[i];
        }
    }

    v->visited = true;
    v->distance = 0;

    queue<vertex*> v1;
    v1.push(v);
    cout << "Starting vertex (root): " << v->name << "-> ";

    while(!v1.empty()){
        vertex *n = v1.front();
        v1.pop();
        n->visited = true;

        for(int i = 0; i < n->adj.size();i++){
            if(!(n->adj[i].v)->visited){
                n->adj[i].v->distance = n->distance+1;
                n->adj[i].v->visited = true;
                cout << n->adj[i].v->name << "(" << n->adj[i].v->distance << ")" << " ";
                v1.push(n->adj[i].v);
            }
        }
        n->visited=true;
    }
}

void DFT(vertex*v){
    if(v->visited == false){ //if node not visited
        v->visited = true; //count node as visited
        for(int i = 0; i < v->adj.size();i++){ //go thru vertex size
            DFT(v->adj[i].v); //recursive call of adjacent index 
        }
    }
}

int Graph::getConnectedBuildings()
{
    int index = 0; //counter
    for(int i = 0; i < vertices.size(); i++){ //traverse
        if(vertices[i]->visited == false){
            DFT(vertices[i]); //call helper
            index++; //increment
        }
    }
    return index; //return count
}