#include <vector>
#include <iostream>
#include <climits>
#include "Graph.hpp"

using namespace std;

template<class T>
void Graph<T>::restaurants(Node<T>* node){
    if (node-> left != NULL){
        restaurants(node->left);
    }
    cout<< node->name << " " << node->rating << " " << node->cost << endl;

    if (node->right != NULL){
        restaurants(node->right);
    }

    return;
}

template<class T>
bool Graph<T>::adjacent(T v1, T v2){
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices[i].adj.size(); j++){
                if(vertices[i].adj[j].v->name == v2){
                    return true;
                }
            }
        }
    }
    return false;
}




template<class T>
void BSTree<T>::inser(T name, T rating, T cost){
    Node<T>* newNode = new Node<T> (name,rating, cost, NULL,NULL,NULL);
    if (root == NULL){
        root = newNode;
    }
    else{
        Node<T>* temp = root;
        Node<T>* parent = temp;
        while (temp != NULL){
            parent = temp;
            if(name < temp ->name){
                temp = temp->left;
            }
            else{
                temp = temp->right;
            }

        }
        if (name < parent->name){
            parent->left = newNode;
            newNode->parent=parent;
        }
        else{
            parent->right = newNode;
            newNode->parent = parent;
        }
    }
}

template<class T>
BSTree<T>::BSTree(){
    root = NULL;
};



template<class T>
vertex<T>* Graph<T>::Dijkstra(T start, T endd){
    vertex<T> *s, *solvedV, *parent;
    int dist, minDistance;


    vertex<T> *startV = searchG(start);
    vertex<T> *endV = searchG(endd);
    startV->solved = true;
    startV->distance = 0;
    startV->parent = NULL;
    vector < vertex<T> > solved;
    solved.push_back(*startV);

    while (endV->solved != true){
        minDistance = MAXINT;
        solvedV = NULL;
        for(int x = 0; x < solved.size(); x++){
            s = &solved[x];
            parent = s;
            for (int y = 0; y < s->adj.size(); y++){
                if(s->adj[y].v->solved != true){
                    dist = s->distance + s->adj[y].weight;
                    if(dist < minDistance){
                        solvedV = s->adj[y].v;
                        minDistance = dist;
                        parent = s;


                    }
                }
            }
        }
        solvedV->distance = minDistance;
        solvedV->parent = parent;
        solvedV->solved = true;
        solved.push_back(*solvedV);
    }



    return endV;
}

template<class T>
vertex<T>* Graph<T>::searchG(T name){
    for (int i = 0; i < vertices.size(); i++){
        if (vertices[i].name == name){
            return &vertices[i];
        }
    }
    return NULL;
}

template<class T>
Graph<T>::Graph()
{
    MAXINT = INT_MAX;
}

template<class T>
Graph<T>::~Graph()
{
    //dtor

}

template<class T>
void Graph<T>::addEdge(T v1, T v2, int weight){

    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == v1){
            for(int j = 0; j < vertices.size(); j++){
                if(vertices[j].name == v2 && i != j){
                    adjVertex<T> av;
                    av.v = &vertices[j];
                    av.weight = weight;
                    vertices[i].adj.push_back(av);
                }
            }
        }
    }
}
template<class T>
void Graph<T>::addVertex(T n){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i].name == n){
            found = true;
            cout<<vertices[i].name<<" found."<<endl;
        }
    }
    if(found == false){
        vertex<T> v;
        v.name = n;
        v.solved = false;
        vertices.push_back(v);

    }
}

template<class T>
void Graph<T>::displayEdges(){
    string separator = "-->";
    //loop through all vertices and adjacent vertices
    for(int i = 0; i < vertices.size(); i++){

        cout<<vertices[i].name<<"-->";
        for(int j = 0; j < vertices[i].adj.size(); j++){
            cout<<vertices[i].adj[j].v->name<<"***";
        }
        cout<<endl;
    }
}
