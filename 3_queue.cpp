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
            queeee[i] = 0;
        }
    }
    ~queee() // DESTRUCTOR
    {
        cout << "Match queue closed." << endl;
    }
    bool IsEmpty() {
        return fron == rear; // Simplified
    }
    bool IsFull() {
        return rear == max_size - 1; // Simplified
    }
    void enqueue(int inpt) // input variable in queue
    {
        if (!IsFull()) {
            if (IsEmpty()) {
                fron = 0; // Set fron to 0 when the first element is added
            }
            rear++; // Increment rear
            queeee[rear] = inpt; // Add player to the queue
            cout << "Player " << inpt << " joined the match queue." << endl;
        }
        else {
            cout << "Match queue is full. Please try again later." << endl;
        }
    }
    void dequeue() // remove variable from queue
    {
        if (!IsEmpty()) {
            cout << "Player " << queeee[fron] << " has been matched." << endl;
            queeee[fron] = 0; // Optional: Clear the matched player
            fron++; // Move fron to the next player
            // Reset the queue if it's empty after dequeue
            if (fron > rear) {
                fron = rear = -1; // Reset the queue
            }
        }
        else {
            cout << "Match queue is empty." << endl;
        }
    }
    void display() // display all elements of the queue
    {
        cout << "Current match queue: ";
        for (int i = 0; i < max_size; i++) {
            cout << queeee[i] << " ";
        }
        cout << endl;
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
            check = 0;
            break;
        default:
            cout << "Error, wrong input. Please try again." << endl;
        }
    }
}
