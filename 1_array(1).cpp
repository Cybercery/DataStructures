#include <iostream>
using namespace std;
# define size 100  // maximum size

// INSERT ELEMENT
int* insertX(int n, int* length, int pos, int arr[])
{
    if(pos<0)
    {
        cout << "Error: No negative numbers allowed" <<endl;
        return arr;
    }
    if(pos>=*length)
    {
        pos = *length;
    }
	for(int i = *length; i > pos; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[pos] = n;
    *length = *length + 1;
	return arr;
}
// DELETE  ELEMENT
int* deleteAt(int* length, int pos, int arr[])
{
    if(pos<0)
    {
        cout << "Error: No negative numbers allowed! " <<endl<<endl;
        return arr;
    }
    arr[pos] = 0;
    for(int i = pos; i < *length; i++)
    {
        arr[i] = arr[i+1];
    }

    *length = *length - 1;
	return arr;
}

// DISPLAY ARRAY
int displayArray(int length, int arr[])
{
    cout<<"Elements of the array: { ";
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] <<" ";
    }
    cout <<"}"<<endl;
}
int main()
{
    int arr_size = 100;

    START:
        cout << "Enter array size: ";
        cin >> arr_size;

        if (arr_size < 0)
        {
        cout << "Error: No negative numbers allowed! " <<endl<<endl;
        goto START;
        }

        int array1[size];
        cout<<"Enter array: ";
        for(int i = 0; i < arr_size; i++)
        {
            cin>>array1[i];
        }

        displayArray(arr_size, array1);

        int choice = 0;
        int flag = 1;
        int pos;
        int n = 0; //INPUT NUMBER
        while (flag)
        {
            cout << "Choose an operation for the array: " <<endl;
            cout << "1. Insert Element" <<endl;
            cout << "2. Delete Element" <<endl;
            cout << "3. Display Array " <<endl;
            cout << "4.. Exit " <<endl;
            cin >> choice;
            switch(choice)
            {
            case 1: // ENTER AT ANY POSITION
                cout<<"Enter number: ";
                cin >> n;
                cout <<"Enter position: ";
                cin >> pos;
                insertX(n, &arr_size, pos, array1);
                break;
            case 2: // DELETE AT ANY POSITION
                cout <<"Enter position: ";
                cin >> pos;
                deleteAt(&arr_size, pos, array1);
                break;
            case 3: // DISPLAY ARRAY
                displayArray(arr_size, array1);
                break;
            case 4: //END CODE
                flag = 0;
                break;
            default:
                cout<<"Invalid Input";
            }
        }
        cout<<endl<<"Goodbye!";
    return 0;
}
