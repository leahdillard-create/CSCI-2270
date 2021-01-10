#include "Assignment9.hpp"
#include <vector>
#include <queue>
#include <iostream>
#include <cassert>
#include <climits>
#define INT_MAX

using namespace std;

void Graph::createEdge(string v1, string v2, int num){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name==v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j]->name==v2 && i != j){
                    adjVertex adjacentV;
                    adjacentV.v = vertices[j];
                    adjacentV.weight = num; 
                    vertices[i]->adj.push_back(adjacentV);

                    adjVertex adjacentV2;
                    adjacentV2.v = vertices[i];
                    adjacentV2.weight = num;
                    vertices[j]->adj.push_back(adjacentV2);
                }
            }
        }
    }
}

void Graph::insertVertex(string n){
    bool flag = false;

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name==n){
            flag= true;
        }
    }
    if(flag == false){
        vertex *v = new vertex;
        v->name = n;
        v->distance = 0;
        vertices.push_back(v);
    }
}

void Graph::displayEdges(){
    //loop through all vertices and adjacent vertices
    // cout<<"here"<<vertices.size()<<endl;
    for(unsigned int i = 0; i < vertices.size(); i++){
        cout<<vertices[i]->name<<":"<<endl;
        for(unsigned int j = 0; j < vertices[i]->adj.size(); j++){
            cout<<" --> "<< vertices[i]->adj[j].v->name << " "<<vertices[i]->adj[j].weight<<endl;
        }
        cout<<endl;
    }
}
#include <bits/stdc++.h>
void Graph::traverseWithDijkstra(string start){
    vector<vertex*> solved_list;
    
    vertex *vStart = NULL;
    for(int i = 0; i < vertices.size();i++){
        if(vertices[i]->name == start){
            vStart = vertices[i];
        }
    }
    
    vStart->visited = true;
    vStart->distance=0;
    solved_list.push_back(vStart);

    bool allSolved = false;

    while(!allSolved){
        int minDist = INT_MAX;
        vertex* to_add = NULL;
        allSolved = true;

        for(int i = 0; i < solved_list.size();i++){
            vertex *solved = solved_list[i];

            for(int j = 0; j < solved->adj.size();j++){
                if(!solved->adj[j].v->visited){
                    int dist = solved->distance + solved->adj[j].weight; 

                    if(dist<minDist){
                        to_add = solved->adj[j].v;
                        minDist = dist;
                        //solved.adj[j]->pred = solved;
                    }
                    allSolved = false;
                }
            }
        }
        if(!allSolved){
            to_add->distance = minDist;
            to_add->visited = true;
            solved_list.push_back(to_add);
        }
    }
}

vertex* findVertex(vector<vertex*> vertices, string name) {
    // Also note how we return as soon as we find the element we're looking for, enabling better performance
    for (int i = 0; i < vertices.size(); i++) {
        if (vertices[i]->name == name) { 
            return vertices[i]; 
        }
    }
    assert(("Vertex not found!", false));
}

void dfs(vertex* v) {
    // Print
    cout << v->name << " -> ";
    // Mark as visited
    v->visited = true;

    // Recursively visit all unvisited nodes
    for (int i=0; i<v->adj.size(); i++) {
        vertex* neighbor = v->adj[i].v;
        if (!neighbor->visited) { 
            dfs(neighbor); 
        }
    }
}

void Graph::depthFirstTraversal(string sourceVertex) {
    vertex* v = findVertex(vertices, sourceVertex);

    // Set all visited flags to false to start with
    for (int i=0; i<vertices.size(); i++) { 
        vertices[i]->visited = false; 
    }

    dfs(v);
    cout << "DONE";
}

/*
#include <stack>
void Graph::depthFirstTraversal(string sourceVertex)
{
    vertex *vStart = NULL;

    for(int i = 0; i < vertices.size();i++){
        if(vertices[i]->name == sourceVertex){
            vStart = vertices[i];
        }
    }

    vStart->visited = true;
    vStart->distance = 0;

    stack<vertex*> v1;
    v1.push(vStart);

    while(!v1.empty()){
       
        vertex *n = v1.top();
        v1.pop();
        n->visited = true;
        cout << n->name << " -> ";

        for(int i = 0; i < n->adj.size();i++){
            if(n->adj[i].v->visited){
                continue;
            }
            v1.push(n->adj[i].v);   
            break;
        }
    }

    cout << "DONE";
}
*/

void minDistHelper(vertex* src, vertex* current) {
  
    if (current == src) {
        cout << src->name;
    }
    else {
        minDistHelper(src, current->pred);
        cout << " -> " << current->name;
    }
}

void Graph::minDistPath(string source, string destination) {
    traverseWithDijkstra(source); //run dijkstra thru all nodes

    vertex* v_src = findVertex(vertices, source); //find
    vertex* v_dest = findVertex(vertices, destination); //find

    minDistHelper(v_src, v_dest); //recursive function call
    cout << " -> DONE [" << v_dest->distance << "]\n"; 
}
