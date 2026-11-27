
#include<iostream>

using namespace std;

class Stack;

class Node {

private:

    int value;
    Node* next;

public:

    explicit Node(int value) : value(value), next(nullptr) {}

    friend class Stack;

};

class Stack {

private:

    Node* top = nullptr;
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

        Node* temp = top;

        while (temp != nullptr) {

            cout << temp->value << " ";

            temp = temp->next;

        }

        cout << endl;
    }

    void push(int value) {

        Node* newNode = new Node(value);

        newNode->next = top;
        top = newNode;

        length++;
    }

    bool pop() {

        if (top == nullptr) {

            return false;
        }

        Node* temp = top;

        top = top->next;

        delete temp;

        length--;

        return true;
    }

    bool peek(int& value) const {

        if (top == nullptr) {

            return false;
        }

        value = top->value;

        return true;
    }

    ~Stack() {

        while (top != nullptr) {

            Node* temp = top;

            top = top->next;

            delete temp;

        }

    }

};
