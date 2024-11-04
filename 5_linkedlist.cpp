#include <iostream>
#include <string>
using namespace std;

class Song
{
public:
    string title;
    string author;

    Song(string t, string a)
    {
        title = t;
        author = a;
    }
};

class Node
{
public:
    Song* data;
    Node(Song* song)
    {
        this->data = song;
        this->next = NULL;
    }
    Node* next;
};

class LinkedList
{
public:
    Node* head;

    LinkedList()
    {
        this->head = NULL;
    }

    ~LinkedList()
    {
        cout << "Freeing memory... Linked list destroyed." << endl;
    }

    int GetSize()
    {
        Node* temp = head;
        int cnt = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }

    void InsertAtHead(string title, string author)
    {
        Song* newSong = new Song(title, author);
        Node* newNode = new Node(newSong);
        newNode->next = head;
        head = newNode;
        cout << "Inserted \"" << title << "\" by " << author << " at the beginning of the list." << endl;
    }

    void InsertAtTail(string title, string author)
    {
        Song* newSong = new Song(title, author);
        Node* newNode = new Node(newSong);
        if (head == NULL)
        {
            InsertAtHead(title, author);
            return;
        }
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Inserted \"" << title << "\" by " << author << " at the end of the list." << endl;
    }

    void InsertAtPosition(string title, string author, int pos)
    {
        Song* newSong = new Song(title, author);
        Node* newNode = new Node(newSong);
        Node* temp = head;
        int len = GetSize();
        if (head == NULL || pos <= 0)
        {
            InsertAtHead(title, author);
            return;
        }
        if (pos >= len)
        {
            InsertAtTail(title, author);
            return;
        }
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        Node* temp1 = temp->next;
        temp->next = newNode;
        newNode->next = temp1;
        cout << "Inserted \"" << title << "\" by " << author << " at position " << pos << "." << endl;
    }

    int DeleteAtHead()
    {
        Node* temp = head;
        head = head->next;
        string deletedTitle = temp->data->title;
        string deletedAuthor = temp->data->author;
        delete temp->data; // Free the song memory
        delete temp; // Free the node memory
        cout << "Deleted \"" << deletedTitle << "\" by " << deletedAuthor << " from the beginning of the list." << endl;
        return 0; // Return 0 for consistency
    }

    int DeleteAtTail()
    {
        Node* temp = head;
        if (head == NULL)
        {
            cout << "List is empty. Cannot delete anything." << endl;
            return -999;
        }
        if (head->next == NULL)
        {
            string deletedTitle = head->data->title;
            string deletedAuthor = head->data->author;
            delete head->data; // Free the song memory
            delete head; // Free the node memory
            head = NULL;
            cout << "Deleted \"" << deletedTitle << "\" by " << deletedAuthor << " from the end of the list." << endl;
            return 0; // Return 0 for consistency
        }
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        Node* last = temp->next;
        string deletedTitle = last->data->title;
        string deletedAuthor = last->data->author;
        delete last->data; // Free the song memory
        delete last; // Free the node memory
        temp->next = NULL;
        cout << "Deleted \"" << deletedTitle << "\" by " << deletedAuthor << " from the end of the list." << endl;
        return 0; // Return 0 for consistency
    }

    int DeleteAtPosition(int pos)
    {
        Node* temp = head;
        int len = GetSize();
        if (head == NULL)
        {
            cout << "List is empty. Cannot delete anything." << endl;
            return -999;
        }
        if (pos <= 0)
        {
            return DeleteAtHead();
        }
        if (pos >= len)
        {
            return DeleteAtTail();
        }
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        Node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        string deletedTitle = nodeToDelete->data->title;
        string deletedAuthor = nodeToDelete->data->author;
        delete nodeToDelete->data; // Free the song memory
        delete nodeToDelete; // Free the node memory
        cout << "Deleted \"" << deletedTitle << "\" by " << deletedAuthor << " at position " << pos << "." << endl;
        return 0; // Return 0 for consistency
    }

    void Display()
    {
        Node* temp = head;
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }
        cout << "Songs in the List: " << endl;
        while (temp != NULL)
        {
            cout << "\"" << temp->data->title << "\" by " << temp->data->author << endl;
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    int choice;
    int check = 1;
    LinkedList ll;
    string title, author;
    int pos;
    while (check)
    {
        cout << endl << "1 - Insert at head" << endl;
        cout << "2 - Insert at tail" << endl;
        cout << "3 - Insert at position" << endl;
        cout << "4 - Delete at head" << endl;
        cout << "5 - Delete at tail" << endl;
        cout << "6 - Delete at position" << endl;
        cout << "7 - Display" << endl;
        cout << "8 - Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            cout << "Enter song title: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, title);
            cout << "Enter author name: ";
            getline(cin, author);
            ll.InsertAtHead(title, author);
            break;
        case 2:
            cout << "Enter song title: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, title);
            cout << "Enter author name: ";
            getline(cin, author);
            ll.InsertAtTail(title, author);
            break;
        case 3:
            cout << "Enter song title: ";
            cin.ignore(); // Clear the input buffer
            getline(cin, title);
            cout << "Enter author name: ";
            getline(cin, author);
            cout << "Enter position: ";
            cin >> pos;
            ll.InsertAtPosition(title, author, pos);
            break;
        case 4:
            ll.DeleteAtHead();
            break;
        case 5:
            ll.DeleteAtTail();
            break;
        case 6:
            cout << "Enter position: ";
            cin >> pos;
            ll.DeleteAtPosition(pos);
            break;
        case 7:
            ll.Display();
            break;
        case 8:
            check = 0;
            break;
        default:
            cout << "Error: Please input a valid choice." << endl;
        }
    }
    cout << endl << "Exiting... Goodbye!" << endl;
}
