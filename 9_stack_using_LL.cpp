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

// Class to implement stack operations using a linked list
class Stack {

    // Pointer to the top of the stack
    Node* top;

public:
    // Constructor to initialize the top
    Stack() { top = nullptr; }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        return top == nullptr;
    }

    // Function to add a song to the stack
    void push(string new_song) {

        // Create a new linked list node
        Node* new_node = new Node(new_song);

        // Make the new node the top of the stack
        new_node->next = top;
        top = new_node;
    }

    // Function to remove a song from the stack
    void pop() {

        // If stack is empty, return
        if (this->isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        // Store the current top and move top one node down
        Node* temp = top;
        top = top->next;

        // Deallocate memory of the old top node
        delete temp;
    }

    // Function to get the top song of the stack
    string peek() {

        // Checking if the stack is empty
        if (this->isEmpty()) {
            cout << "Stack is empty\n";
            return "";
        }
        return top->song;
    }
};

// Driver code to test the stack implementation
int main()
{
    Stack s;
    int choice;
    string song;

    while (true) {
        cout << "\nMusic Player Stack Menu:\n";
        cout << "1. Add Song to Stack\n";
        cout << "2. Remove Song from Stack\n";
        cout << "3. Display Current Song\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // To ignore the newline character after the choice input

        switch (choice) {
        case 1:
            cout << "Enter song to add to stack: ";
            getline(cin, song);
            s.push(song);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            cout << "Current Song: " << s.peek() << endl;
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice, please try again.\n";
        }
    }

    return 0;
}