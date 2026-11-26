#include<iostream>

using namespace std;

template <typename T>
class Graph;

template <typename T>
class Node {

private:

    T vertex;
    Node* next;

public:

    explicit Node(T vertex) : vertex(vertex), next(nullptr) {}

    friend class Graph<T>;

};

template <typename T>
class Graph {

private:

    Node<T>** adjList;
    int vertices;
    int edges;

public:

    explicit Graph(int vertices) : vertices(vertices), edges(0) {

        adjList = new Node<T>*[vertices];

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

    void add_edge(T source, T destination) {

        if (source < 0 || source >= vertices ||
            destination < 0 || destination >= vertices) {

            return;

        }

        Node<T>* newNode = new Node<T>(destination);

        newNode->next = adjList[source];

        adjList[source] = newNode;


        newNode = new Node<T>(source);

        newNode->next = adjList[destination];

        adjList[destination] = newNode;

        edges++;

    }

    void display() const {

        for (int i = 0; i < vertices; i++) {

            cout << i << " -> ";

            Node<T>* temp = adjList[i];

            while (temp != nullptr) {

                cout << temp->vertex << " ";

                temp = temp->next;

            }

            cout << endl;

        }

    }

    bool has_edge(T source, T destination) const {

        if (source < 0 || source >= vertices ||
            destination < 0 || destination >= vertices) {

            return false;

        }

        Node<T>* temp = adjList[source];

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

            Node<T>* temp = adjList[i];

            while (temp != nullptr) {

                Node<T>* nodeToDelete = temp;

                temp = temp->next;

                delete nodeToDelete;

            }

        }

        delete[] adjList;

    }

};