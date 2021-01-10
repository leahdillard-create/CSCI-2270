#include <iostream>
#include <vector>
#include <queue>
#include "graph.hpp"

using namespace std;

void Graph::addEdge(string v1, string v2){
    for(int i = 0; i < vertices.size();i++){
        if(vertices[i]->name==v1){
            for(int j = 0; j < vertices.size();j++){
                if(vertices[i]->name == v1 && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                    adjVertex av2;
                    av.v= vertices[i];
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}

void Graph::addVertex(string n){
    bool found = false;
    //check if vertex exist
    //else create vertex
    for(int i = 0; i < vertices.size();i++){
        if(vertices[i]->name==n){
            found = true;
            cout<< vertices[i]->name<<" found." << endl;
        }
    }
    if(found ==false){
        vertex *v = new vertex; //creating a new vertex pointer
        v->name = n; //initialize
        v->distance = 0; //initialize
        vertices.push_back(v); //push v back onto the vector
    }
}
void Graph::displayEdges(){
    for(int i = 0; i < vertices.size(); i++){
        cout << vertices[i]->name << " ---> ";
        for(int j = 0; j< vertices[i]->adj.size();j++){
            cout << vertices[i]->adj[j].v->name << " ";
        }
        cout << endl;
    }
}
void Graph::displayVerticesObj(){
    for(vector <vertex*>::iterator vObj = vertices.begin(); vObj!=vertices.end(); ++vObj){
        auto position = vObj - vertices.begin();
        cout << "vertices[" << position << "]:" << *vObj << endl;
    }
}
void Graph::breadthFirstTraverse(string sourceVertex){
    //Since we are not given a serach function, we need to implement it here to find the starting vertex

    //need a pointer to keep track of starting vertex
    vertex *vStart;

    //Since a vector object is used, the serach is just a for-loop
    for(){
        if(vertices[i]->name==sourceVertex){
            vStart = vertices[i];
        }
        vStart->visited = true;

        queue<vertex*> q;
        q.push(vStart);

        vertex *n;

        while(!q.empty()){
            n = q.front();
            q.pop();
            //scan adj list of each element in Q
            for(){
                
            }
        }
    }
}
void Graph::depthFirstTraverse(string sourceVertex){

}
