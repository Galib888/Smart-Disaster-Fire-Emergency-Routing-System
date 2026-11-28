#include<iostream>

using namespace std;

template <typename T>
class Queue;

template <typename T>
class Node {

private:

    T value;
    Node<T>* next;

public:

    explicit Node(T value) : value(value), next(nullptr) {}

    friend class Queue<T>;

};

template <typename T>
class Queue {

private:

    Node<T>* front = nullptr;
    Node<T>* rear = nullptr;
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

        Node<T>* temp = front;

        while (temp != nullptr) {

            cout << temp->value << " ";

            temp = temp->next;

        }

        cout << endl;
    }

    void enqueue(T value) {

        Node<T>* newNode = new Node<T>(value);

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

        Node<T>* temp = front;

        front = front->next;

        delete temp;

        length--;

        if (front == nullptr) {

            rear = nullptr;
        }

        return true;
    }

    bool peek(T& value) const {

        if (front == nullptr) {

            return false;
        }

        value = front->value;

        return true;
    }

    ~Queue() {

        while (front != nullptr) {

            Node<T>* temp = front;

            front = front->next;

            delete temp;

        }

        rear = nullptr;

    }

};