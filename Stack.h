#include<iostream>

using namespace std;

template <typename T>
class Stack;

template <typename T>
class Node {

private:

    T value;
    Node<T>* next;

public:

    explicit Node(T value) : value(value), next(nullptr) {}

    friend class Stack<T>;

};

template <typename T>
class Stack {

private:

    Node<T>* top = nullptr;
    int length = 0;

public:

    Stack() = default;
    Stack(const Stack&) = delete;

    int stack_size() const {

        return length;
    }

    bool is_empty() const {

        return top == nullptr;
    }

    void display() const {

        Node<T>* temp = top;

        while (temp != nullptr) {

            cout << temp->value << " ";

            temp = temp->next;

        }

        cout << endl;
    }

    void push(T value) {

        Node<T>* newNode = new Node<T>(value);

        newNode->next = top;
        top = newNode;

        length++;
    }

    bool pop() {

        if (top == nullptr) {

            return false;
        }

        Node<T>* temp = top;

        top = top->next;

        delete temp;

        length--;

        return true;
    }

    bool peek(T& value) const {

        if (top == nullptr) {

            return false;
        }

        value = top->value;

        return true;
    }

    ~Stack() {

        while (top != nullptr) {

            Node<T>* temp = top;

            top = top->next;

            delete temp;

        }

    }

};