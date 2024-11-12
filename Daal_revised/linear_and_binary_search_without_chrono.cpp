
// Binary search without chrono
#include <iostream>
#include <cstdlib>
using namespace std;

void bubbleSort(int arr[], int n);
int linearSearch(int arr[], int n, int x);
int binarysearch(int arr[], int beg, int end, int m);

int main() {
    int n;
    cout << "Enter how many numbers you want: ";
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 101;
    }

    cout << "Array before sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    // Sort the array using bubble sort
    bubbleSort(arr, n);
    cout << "\nArray after sorting: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    int choice;
    while (true) {
        cout << "\nChoose the search method:" << endl;
        cout << "1. Linear Search" << endl;
        cout << "2. Binary Search" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;

        if (choice == 1) {
            // Performing linear search
            int searchElement;
            cout << "\nEnter which number to be found (for linear search): ";
            cin >> searchElement;

            int resultLinear = linearSearch(arr, n, searchElement);

            if (resultLinear != -1) {
                cout << "\nElement found at index " << resultLinear << " using linear search.";
            } else {
                cout << "\nElement not found using linear search.";
            }
        } 
        else if (choice == 2) {
            // Perform binary search
            int searchElement;
            cout << "\nEnter which number to be found (for binary search): ";
            cin >> searchElement;

            int resultBinary = binarysearch(arr, 0, n - 1, searchElement);

            if (resultBinary != -1) {
                cout << "Element found at index " << resultBinary << " using binary search.";
            } else {
                cout << "Element not found using binary search.";
            }
        } 
        else if (choice == 3) {
            break;
        } 
        else {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int binarysearch(int arr[], int beg, int end, int m) {
    while (beg <= end) {
        int mid = (beg + end) / 2;
        if (arr[mid] == m) {
            return mid;
        } else if (arr[mid] > m) {
            return binarysearch(arr, beg, mid - 1, m);
        } else {
            return binarysearch(arr, mid + 1, end, m);
        }
    }
    return -1;
}

