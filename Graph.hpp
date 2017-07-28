#ifndef GRAPH_HPP_INCLUDED
#define GRAPH_HPP_INCLUDED

template<class T>
struct vertex;

template<class T>
struct Node {
    T name;
    T rating;
    T cost;
    Node* parent;
    Node* left;
    Node* right;
    Node(T na, T ra, T co, Node* p, Node* l, Node* r): name(na), rating(ra), cost(co),parent (p), left(l), right(r){};
};


template<class T>
class BSTree{
private:
    Node<T>* searchRecursive(Node<T>* node, T name);
public:
    BSTree();
    void inser(T name, T rating, T cost);
    Node<T>* searc(T name);
    void traversePrint(Node<T>* node);
        Node<T>* root;

};




template<class T>
struct adjVertex{
    vertex<T> *v;
    int weight;
};

template<class T>
struct vertex{
    T name;
    std::vector<adjVertex<T> > adj;
    bool solved;
    int distance;
    Node<T>* restaurants;
    vertex<T> *parent;
};

template<class T>
class Graph
{
    public:
        Graph();
        ~Graph();
        void addEdge(T v1, T v2, int weight);
        void addVertex(T name);
        void displayEdges();
        vertex<T>* searchG(T name);
        vertex<T> *Dijkstra(T start, T endd);
        void restaurants(Node<T>* node);
        bool adjacent(T v1, T v2);
    protected:
    private:
        vertex<T> nullvrtx;
        std::vector<vertex<T> > vertices;
        int MAXINT;
};


#endif // GRAPH_HPP_INCLUDED
