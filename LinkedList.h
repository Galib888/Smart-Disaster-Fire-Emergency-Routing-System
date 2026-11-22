
#include<iostream>

using namespace std;

template <typename T>
class LinkedList;

template <typename T>
class Node {

private:

    T value;
    Node<T>* next;

public:

    explicit Node(T value) : value(value), next(nullptr) {}

    friend class LinkedList<T>;

};

template <typename T>
class LinkedList {

private:

    Node<T>* head = nullptr;
    int length = 0;

public:

    LinkedList() = default;
    LinkedList(const LinkedList&) = delete;

    int list_size() const {

        return length;
    }

    void display() const {

        Node<T>* temp = head;

        while (temp != nullptr) {

            cout << temp->value << " ";

            temp = temp->next;

        }

        cout << endl;
    }

    void insert_at_head(T value) {

        Node<T>* newNode = new Node<T>(value);

        newNode->next = head;
        head = newNode;

        length++;
    }

    void insert_at_tail(T value) {

        Node<T>* newNode = new Node<T>(value);

        if (head == nullptr) {

            head = newNode;
            length++;

            return;
        }

        Node<T>* temp = head;

        while (temp->next != nullptr) {

            temp = temp->next;

        }

        temp->next = newNode;
        length++;

    }

    bool insert_at_index(T value, int index) {

        if (index < 0 || index > length) {
            return false;
        }

        if (index == 0) {

            insert_at_head(value);

            return true;

        }

        if (index == length) {

            insert_at_tail(value);

            return true;

        }

        Node<T>* newNode = new Node<T>(value);

        Node<T>* temp = head;

        for (int i = 0; i < index - 1; i++) {

            temp = temp->next;

        }

        newNode->next = temp->next;

        temp->next = newNode;

        length++;

        return true;

    }

    bool delete_head() {

        if (head == nullptr) {
            return false;
        }

        Node<T>* temp = head;

        head = head->next;

        delete temp;
        length--;

        return true;
    }

    bool delete_tail() {

        if (head == nullptr) {

            return false;

        }

        if (head->next == nullptr) {

            delete head;
            head = nullptr;
            length--;
            return true;

        }

        Node<T>* temp = head;

        while (temp->next->next != nullptr) {

            temp = temp->next;

        }

        delete temp->next;
        temp->next = nullptr;
        length--;
        return true;
    }

    bool delete_at_index(int index) {

        if (index < 0 || index > length) {
            return false;
        }

        if (index == 0) {

            return delete_head();
        }

        Node<T>* temp = head;

        for (int i = 0; i < index - 1; i++) {

            temp = temp->next;

        }

        Node<T>* nodeToDelete = temp->next;

        temp->next = nodeToDelete->next;

        delete nodeToDelete;

        length--;

        return true;

    }

    bool move_tail_to_head() {

        if (head == nullptr) {

            return false;

        }

        if (head->next == nullptr) {

            return false;

        }

        Node<T>* temp = head;

        while (temp->next->next != nullptr) {

            temp = temp->next;

        }

        Node<T>* last = temp->next;

        temp->next = nullptr;

        last->next = head;

        head = last;

        return true;
    }

    ~LinkedList() {

        while (head != nullptr) {

            Node<T>* temp = head;

            head = head->next;

            delete temp;

        }

    }

};
