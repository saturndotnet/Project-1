#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (rear == nullptr) {  // If queue is empty
            //**** Please add your code here 
            //1
            front = rear = newNode;
            return;


            //**** End of adding your code
        }
        //**** Please add your code here 
        //2
        rear->next = newNode;
        rear = newNode;


        //**** End of adding your code
    }

    int dequeue() {
        if (isEmpty()) {
            //cout << "Queue is empty\n";
            return -1;
        }
        Node* temp = front;
        int removedData = temp->data;
        //**** Please add your code here 
        //3
        front = front->next;


        //**** End of adding your code

        if (front == nullptr) // If queue becomes empty
            rear = nullptr;

        //**** Please add your code here 
        //4
        delete temp;
        return removedData;


        //**** End of adding your code
    }

	int peek() { // Returns front element of the queue
        if (isEmpty()) {
            //cout << "Queue is empty\n";
            return -1;
        }
        //**** Please add your code here 
        //5
        return front->data;


        //**** End of adding your code
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return;
        }
        Node* current = front;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display(); // Output: 10 -> 20 -> 30 -> NULL

    cout << "Dequeued: " << q.dequeue() << endl; // Output: Dequeued: 10
    q.display(); // Output: 20 -> 30 -> NULL

    cout << "Front element: " << q.peek() << endl; // Output: Front element: 20

    cout << "Dequeued: " << q.dequeue() << endl; 
    q.display();

    cout << "Dequeued: " << q.dequeue() << endl;
    q.display(); 

    cout << "Dequeued: " << q.dequeue() << endl; 
    q.display(); 

    return 0;
}
