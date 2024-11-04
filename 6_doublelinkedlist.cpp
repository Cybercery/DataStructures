/*
Name: Soham DOiphode
Roll Number: C005
Division: B
Batch: 1
*/
#include <iostream>
#include <string>
using namespace std;
class Node
{
public:
    // members
    int data;
    Node *next;
    Node *prev;
    // constructor
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class LinkedList
{
public:
    Node *head;
    LinkedList()
    {
        this->head = NULL;
    }
    ~LinkedList()
    {
        DeleteList();
    }

    int GetSize()
    {
        Node *temp = head;
        int cnt = 0;
        while (temp != NULL)
        {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
    void InsertAtHead(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        newNode->prev = NULL;
    }
    void InsertAtTail(int val)
    {
        Node *newNode = new Node(val);
        // if list is empty
        if (head == NULL)
        {
            InsertAtHead(val);
            return;
        }
        // inserting at tail if list is not empty
        Node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;

        //prev
        newNode->prev = temp;
    }
    void InsertAtPosition(int val, int pos)
    {
        Node *newNode = new Node(val);
        Node *temp = head;
        int len = GetSize();
        // if pos is 0 or negative insert at start(head)
        if (head == NULL)
        {
            InsertAtHead(val);
            return;
        }
        // if pos is greater than size insert at end(tail)
        if (pos >= len)
        {
            InsertAtTail(val);
            return;
        }
        // if position is within size
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        Node *temp1 = temp->next;
        temp->next = newNode;
        newNode->next = temp1;

        //prev
        newNode->prev = temp;
    }
    int DeleteAtHead()
    {
        Node *temp = head;
        head = head->next;
        int DeletedValue = temp->data;
        delete temp;
        return DeletedValue;
    }
    int DeleteAtTail()
    {
        Node *temp = head;
        // if empty
        if (head == NULL)
        {
            cout << "Empty list cannot delete anything\n";
            return -999; // return some random number to tell the guy that he is autistic
        }
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        // now temp is the second last element
        Node *last = temp->next; // last element
        int DeletedNumber = last->data;
        delete last;
        temp->next = NULL; // assign next of second last node to null
        return DeletedNumber;
    }
    int DeleteAtPosition(int pos)
    {
        Node *temp = head;
        int len = GetSize();
        // if empty
        if (head == NULL)
        {
            cout << "Empty list cannot delete anything\n";
            return -999; // return some random number to tell the guy that he is autistic
        }
        if (pos <= 0)
        {
            return DeleteAtHead();
            // return 0;
        }
        if (pos >= len)
        {
            return DeleteAtTail();
            // return 0;
        }
        for (int i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        Node *nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        int num = nodeToDelete->data;
        delete nodeToDelete;
        return num;
    }
    void Display()
    {
        Node *temp = head;
        Node *temp1;
        if (head == NULL)
        {
            cout << "list is empty";
            return;
        }
        while (temp != NULL)
        {
            cout << temp->data << " ";
            if(temp->next==NULL)
            {
                temp1 = temp;
            }
            temp = temp->next;
        }
        cout<<endl;
        while(temp1!= NULL)
        {
            cout << temp1->data << " ";
            temp1 = temp1->prev;
        }


        return;
    }
    void DeleteList()
    {
        // List is empty
        if (head == NULL)
        {
            cout << "Empty list" << endl;
            return;
        }
        // Size of list is 1
        if (head->next == NULL)
        {
            delete head;
            return;
        }
        // Size more than 1
        Node *temp = head->next;
        while (temp != NULL)
        {
            delete head;
            head = temp;
            temp = temp->next;
        }
        delete head;
        head = NULL;
    }
};
int main()
{
    int choice;
    LinkedList ll;
    int value, pos;
    while (2 + 2 != 5)
    {
        cout << "\n1 - insert at head" << endl;
        cout << "2 - insert at tail" << endl;
        cout << "3 - insert at pos" << endl;
        cout << "4 - delete at head" << endl;
        cout << "5 - delete at tail" << endl;
        cout << "6 - delete at pos" << endl;
        cout << "7 - display " << endl;
        cout << "Enter choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter value : ";
            cin >> value;
            ll.InsertAtHead(value);
            break;
        case 2:
            cout << "Enter value : ";
            cin >> value;
            ll.InsertAtTail(value);
            break;
        case 3:
            cout << "Enter value : ";
            cin >> value;
            cout << "Enter position : ";
            cin >> pos;
            ll.InsertAtPosition(value, pos);
            break;
        case 4:
            cout << "deleted value - " << ll.DeleteAtHead();
            break;
        case 5:
            cout << "deleted value - " << ll.DeleteAtTail();
            break;
        case 6:
            cout << "Enter position : ";
            cin >> pos;
            cout << "deleted value - " << ll.DeleteAtPosition(pos);
            break;
        case 7:
            ll.Display();
            break;
        }
    }
    cout << endl;
}
