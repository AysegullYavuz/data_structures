#include <iostream>

//Transferring elements from a queue to the stack

using namespace std;


template <typename T> // Since the data type may be different, we use a template in order not to limit it.
class Node {
public:
    T data; // data is defined
    Node* next; //We use pointer to access the next node

    Node(T value) {
    data = value;
    next = NULL;
}
};

template <typename T>
class LinkedList {
public:
    Node<T>* front;
    Node<T>* rear;

  LinkedList() {
    front = NULL;
    rear = NULL;
}
 

    void enqueue(T val) { 
        Node<T>* newNode = new Node<T>(val);
        if (front == NULL) {
            front = rear = newNode;  //When a single element is added, front and rear will show the same node.
        } else {
            rear->next = newNode;// next of the last node will point to the new node
            rear = newNode;// rear is updated
        }
    }

    void dequeue() { 
        if (!isEmpty()) {
            Node<T>* temp = front;// We make a temp assignment to the front because we will delete this node
            front = front->next;// We determine the new front of the queue
            delete temp; // We delete the temp assignment we made from memory
            if (front == NULL) {// If there is only one element in the queue, removing it will make the queue empty
                rear = NULL;// Last element removed
            }
        }
    }

    T frontElement() {
        if (!isEmpty()) {
            return front->data;// The value of the leading element is returned.
        }
        return T();// return default value if queue is empty
    }

    bool isEmpty() {
        return front == NULL;
    }
};
// Stack class
template <typename T>

class Stack {
private:
    LinkedList<T> list;

public:
    void push(T val) {
        list.enqueue(val);
    }

    void pop() {
        list.dequeue();
    }

    T topElement() { 
        return list.frontElement();
    }

    bool isEmpty() {
        return list.isEmpty();
    }
};

int main() {
    // Create a Queue with linked list
    LinkedList<int> myQueue;

    // Adding elements
    myQueue.enqueue(3);//front
    myQueue.enqueue(2);
    myQueue.enqueue(5);
    myQueue.enqueue(7);
    myQueue.enqueue(1);//rear

    // Removes elements from Queue and adds them to firstStack
    Stack<int> firstStack;
    while (!myQueue.isEmpty()) { // The loop continues until the queue is empty
        int element = myQueue.frontElement(); //It is assigned to the front element variable
        myQueue.dequeue();
        firstStack.push(element);
    }

    // Print the contents of the firstStack to the screen
    cout << "First Stack: ";
    while (!firstStack.isEmpty()) { //The loop continues until the firstStack is empty 
        cout << firstStack.topElement() << " ";
        firstStack.pop();// top element is removed
    }

    return 0;
}
