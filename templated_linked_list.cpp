#include <iostream>
#include <string>

template<typename T>
struct Node {
    T data;
    Node* next;

    Node(const T& data) : data(data), next(nullptr) {}
};

template<typename T>
class list {
private:
    Node<T>* head;

public:
    list() : head(nullptr) {}

    // Function to push a new element to the front of the list
    void push(const T& data) {
        Node<T>* newNode = new Node<T>(data);
        newNode->next = head;
        head = newNode;
    }

    // Function to apply a function to all elements of the list
    template<typename Func>
    void apply_to_all(Func func) {
        Node<T>* current = head;
        while (current != nullptr) {
            func(current->data);
            current = current->next;
        }
    }

    // Overloading the << operator for easy printing
    friend std::ostream& operator<<(std::ostream& out, const list<T>& lst) {
        Node<T>* current = lst.head;
        out << "[";
        while (current != nullptr) {
            out << current->data;
            current = current->next;
            if (current != nullptr) out << ", ";
        }
        out << "]";
        return out;
    }
};
