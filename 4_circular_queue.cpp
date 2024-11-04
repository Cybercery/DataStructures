#include <iostream>
using namespace std;
#define max_size 5

class queee {
    int fron = -1;
    int rear = -1;
    int queeee[max_size];

public:
    queee() // CONSTRUCTOR
    {
        for (int i = 0; i < max_size; i++) {
            queeee[i] = 0; // Initialize queue elements to 0
        }
    }
    ~queee() // DESTRUCTOR
    {
        cout << "Match queue closed." << endl;
    }
    bool IsEmpty() {
        return fron == -1; // Queue is empty if fron is -1
    }
    bool IsFull() {
        return (fron == 0 && rear == max_size - 1) || (fron == rear + 1); // Check if the queue is full
    }
    void enqueue(int inpt) // INPUT ELEMENT
    {
        if (IsFull()) {
            cout << "Match queue is full. Please try again later." << endl;
        } else {
            if (fron == -1) {
                fron = 0; // Set fron to 0 when the first player is added
            }
            rear = (rear + 1) % max_size; // Circular increment
            queeee[rear] = inpt; // Add player to the queue
            cout << "Player " << inpt << " joined the match queue." << endl;
        }
    }
    void dequeue() // DELETE ELEMENT
    {
        if (IsEmpty()) {
            cout << "Match queue is empty." << endl;
        } else {
            cout << "Player " << queeee[fron] << " has been matched." << endl;
            fron = (fron + 1) % max_size; // Circular increment
            if (fron == rear) { // Check if the queue is now empty
                fron = -1; // Reset queue
                rear = -1;
            }
        }
    }
    void display() {
        if (IsEmpty()) {
            cout << "Match queue is empty." << endl;
        } else {
            cout << "Current match queue: ";
            for (int i = fron; i != rear; i = (i + 1) % max_size) {
                cout << queeee[i] << " ";
            }
            cout << queeee[rear] << endl; // Display the last element
        }
    }
};

int main() {
    int choice = 0;
    int check = 1;
    int input = 0;

    queee obj;

    while (check) {
        cout << "Choose from the following: " << endl;
        cout << "1. Join match queue" << endl;
        cout << "2. Match players" << endl;
        cout << "3. Display match queue" << endl;
        cout << "4. Exit" << endl;
        cout << "Your Choice: ";

        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter player number: ";
            cin >> input;
            obj.enqueue(input);
            break;
        case 2:
            obj.dequeue();
            break;
        case 3:
            obj.display();
            break;
        case 4:
            check = 0; // Exit the loop
            break;
        default:
            cout << "Error, wrong input. Please try again." << endl;
        }
    }
}
