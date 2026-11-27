
#include<iostream>

using namespace std;

class Queue;

class Node {

private:

    int value;
    Node* next;

public:

    explicit Node(int value) : value(value), next(nullptr) {}

    friend class Queue;

};

class Queue {

private:

    Node* front = nullptr;
    Node* rear = nullptr;
    int length = 0;

public:

    Queue() = default;
    Queue(const Queue&) = delete;

    int queue_size() const {

        return length;
    }

    bool is_empty() const {

        return front == nullptr;
    }

    void display() const {

        Node* temp = front;

        while (temp != nullptr) {

            cout << temp->value << " ";

            temp = temp->next;

        }

        cout << endl;
    }

    void enqueue(int value) {

        Node* newNode = new Node(value);

        if (front == nullptr) {

            front = newNode;
            rear = newNode;

            length++;

            return;
        }

        rear->next = newNode;

        rear = newNode;

        length++;
    }

    bool dequeue() {

        if (front == nullptr) {

            return false;
        }

        Node* temp = front;

        front = front->next;

        delete temp;

        length--;

        if (front == nullptr) {

            rear = nullptr;
        }

        return true;
    }

    bool peek(int& value) const {

        if (front == nullptr) {

            return false;
        }

        value = front->value;

        return true;
    }

    ~Queue() {

        while (front != nullptr) {

            Node* temp = front;

            front = front->next;

            delete temp;

        }

        rear = nullptr;

    }

};
