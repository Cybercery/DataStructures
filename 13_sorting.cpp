#include <iostream>
#include <vector>

using namespace std;

// Function to perform Binary Search
int binarySearch(const vector<int> &arr, int left, int right, int x)
{
    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == x)
            return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Function to perform Insertion Sort
void insertionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Function to merge two halves for Merge Sort
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform Merge Sort
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

int main()
{
    int n, choice, x;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    while (true)
    {
        cout << "Choose an operation:\n";
        cout << "1. Binary Search\n";
        cout << "2. Insertion Sort\n";
        cout << "3. Merge Sort\n";
        cout << "4. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter the element to search: ";
            cin >> x;
            insertionSort(arr); // Ensure the array is sorted before binary search
            cout << "Sorted array: ";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
            int result;
            result = binarySearch(arr, 0, n - 1, x);
            if (result != -1)
                cout << "Element found at index " << result << endl;
            else
                cout << "Element not found" << endl;
            break;
        case 2:
            insertionSort(arr);
            cout << "Sorted array: ";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
            break;
        case 3:
            mergeSort(arr, 0, n - 1);
            cout << "Sorted array: ";
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
            cout << endl;
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}