#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>
#include <bits/stdc++.h>

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

void Graph::depthFirstTraversal(string sourceVertex)
{
    

}

void Graph::minDistPath(string source, string destination) {

}
