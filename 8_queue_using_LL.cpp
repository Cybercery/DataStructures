#include <iostream>
#include <string>
using namespace std;

// Node class representing a single node in the linked list
class Node {
public:
    string song;
    Node* next;
    Node(string new_song)
    {
        this->song = new_song;
        this->next = nullptr;
    }
};

// Class to implement queue operations using a linked list
class Queue {

    // Pointer to the front and the rear of the linked list
    Node *front, *rear;

public:
    // Constructor to initialize the front and rear
    Queue() { front = rear = nullptr; }

    // Function to check if the queue is empty
    bool isEmpty()
    {
        // If the front and rear are null, then the queue is
        // empty, otherwise it's not
        if (front == nullptr) {
            return true;
        }
        return false;
    }

    // Function to add a song to the queue
    void enqueue(string new_song) {

        // Create a new linked list node
        Node* new_node = new Node(new_song);

        // If queue is empty, the new node is both the front
        // and rear
        if (this->isEmpty()) {
            front = rear = new_node;
            return;
        }

        // Add the new node at the end of the queue and
        // change rear
        rear->next = new_node;
        rear = new_node;
    }

    // Function to remove a song from the queue
    void dequeue() {

        // If queue is empty, return
        if (this->isEmpty()) {
            cout << "Queue Underflow\n";
            return;
        }

        // Store previous front and move front one node
        // ahead
        Node* temp = front;
        front = front->next;

        // If front becomes nullptr, then change rear also
        // to nullptr
        if (front == nullptr)
            rear = nullptr;

        // Deallocate memory of the old front node
        delete temp;
    }

    // Function to get the front song of the queue
    string getFront() {
      
      // Checking if the queue is empty
        if (this->isEmpty()) {
            cout << "Queue is empty\n";
            return "";
        }
        return front->song;
    }

    // Function to get the rear song of the queue
    string getRear() {

      // Checking if the queue is empty
        if (this->isEmpty()) {
            cout << "Queue is empty\n";
            return "";
        }
      
        return rear->song;
    }
};

// Driver code to test the queue implementation
int main()
{
    Queue q;
    int choice;
    string song;

    while (true) {
        cout << "\nMusic Player Queue Menu:\n";
        cout << "1. Add Song to Queue\n";
        cout << "2. Remove Song from Queue\n";
        cout << "3. Display Current Song\n";
        cout << "4. Display Last Song in Queue\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character after the choice input

        switch (choice) {
        case 1:
            cout << "Enter song to add to queue: ";
            getline(cin, song);
            q.enqueue(song);
            break;
        case 2:
            q.dequeue();
            break;
        case 3:
            cout << "Current Song: " << q.getFront() << endl;
            break;
        case 4:
            cout << "Last Song in Queue: " << q.getRear() << endl;
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}