#include <iostream>
using namespace std;
#define s_size 5

class Stack {
    int top;
    int arr_stack[s_size];

public:
    Stack()
    {
        top = -1;
        for(int i = 0; i < s_size; i++)
        {
            arr_stack[i] = 0;
        }

    }
    bool IsEmpty()
    {
        if (top==-1)
            return 1;
        else
            return 0;
    }
    bool IsFull()
    {
        if (top == s_size-1)
            return 1;
        else
            return 0;
    }
    void push(int entry)
    {
        if(IsEmpty() || top < s_size-1)
        {
            top++;
            arr_stack[top] = entry;
        }
        else if(IsFull())
        {
            cout << "Stack full"<<endl;
        }
        else
        {
            cout << "I don't really know how you got this";
        }
    }
    void pop()
    {
        if(IsEmpty())
        {
            cout<<"Stack Empty"<<endl;
        }
        else
        {
            arr_stack[top] = 0;
            top--;
        }
    }
    void display()
    {
        cout <<"Elements of the stack: [ ";
        for(int i = 0; i < s_size; i++)
        {
            cout << arr_stack[i] << " ";
        }
        cout <<"]"<<endl;
    }
    void sort_stack()
    {
        if(IsEmpty())
        {
            return;
        }
        int temp = arr_stack[top];
        pop();
        sort_stack();
        insertSorted(temp);
    }

    void insertSorted(int temp)
    {
        if(IsEmpty() || temp > arr_stack[top])
        {
            push(temp);
            return;
        }

        int val = arr_stack[top];
        pop();
        insertSorted(temp);
        push(val);

    }
};

int main()
{
    int choice = 0;
    int check = 1;
    int input = 0;

    Stack obj;

    while(check)
    {
        cout<<"Choose from the following: "<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Pop" <<endl;
        cout<<"3. Sort"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Your Choice: ";

        cin>>choice;

        switch(choice)
        {
        case 1:
            cout<<endl<<"Enter input: ";
            cin >> input;
            obj.push(input);
            break;
        case 2:
            obj.pop();
            break;
        case 3:
            obj.sort_stack();
            break;
        case 4:
            obj.display();
            break;
        case 5:
            check = 0;
        default:
            cout << "Error, wrong input. Please try again.";
        }
    }
}
