
#include<iostream>

using namespace std;

class Graph;

class Node {

private:

    int vertex;
    Node* next;

public:

    explicit Node(int vertex) : vertex(vertex), next(nullptr) {}

    friend class Graph;

};

class Graph {

private:

    Node** adjList;
    int vertices;
    int edges;

public:

    explicit Graph(int vertices) : vertices(vertices), edges(0) {

        adjList = new Node * [vertices];

        for (int i = 0; i < vertices; i++) {

            adjList[i] = nullptr;

        }

    }

    Graph(const Graph&) = delete;

    int vertex_count() const {

        return vertices;
    }

    int edge_count() const {

        return edges;
    }

    void add_edge(int source, int destination) {

        if (source < 0 || source >= vertices ||
            destination < 0 || destination >= vertices) {

            return;

        }

        Node* newNode = new Node(destination);

        newNode->next = adjList[source];

        adjList[source] = newNode;


        newNode = new Node(source);

        newNode->next = adjList[destination];

        adjList[destination] = newNode;

        edges++;

    }

    void display() const {

        for (int i = 0; i < vertices; i++) {

            cout << i << " -> ";

            Node* temp = adjList[i];

            while (temp != nullptr) {

                cout << temp->vertex << " ";

                temp = temp->next;

            }

            cout << endl;

        }

    }

    bool has_edge(int source, int destination) const {

        if (source < 0 || source >= vertices ||
            destination < 0 || destination >= vertices) {

            return false;

        }

        Node* temp = adjList[source];

        while (temp != nullptr) {

            if (temp->vertex == destination) {

                return true;

            }

            temp = temp->next;

        }

        return false;

    }

    ~Graph() {

        for (int i = 0; i < vertices; i++) {

            Node* temp = adjList[i];

            while (temp != nullptr) {

                Node* nodeToDelete = temp;

                temp = temp->next;

                delete nodeToDelete;

            }

        }

        delete[] adjList;

    }

};
