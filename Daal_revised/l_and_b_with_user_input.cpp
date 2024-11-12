
//l_and_b_with_userinput
#include <iostream>
using namespace std;

int n, i, arr[100];

int binarysearch(int arr[], int beg, int end, int m) {
    while (beg <= end) {
        int mid = (beg + end) / 2;
        if (arr[mid] == m) {
            return mid;
        } else if (arr[mid] > m) {
            end = mid - 1;
        } else {
            beg = mid + 1;
        }
    }
    return -1;
}

int linear_search(int arr[], int n, int a) {
    int count = 0; // reset count for each search
    for (int i = 0; i < n; i++) {
        if (arr[i] == a) {
            cout << a << " is present at location " << i + 1 << endl;
            count++;
        }
    }
    return count > 0 ? count : -1;
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

int main() {
    int choice, m, k, result, result1;

    // Taking input of the array
    cout << "Enter the total number of elements: ";
    cin >> n;
    for (i = 0; i < n; i++) {
        cout << "Enter the element for the array: ";
        cin >> arr[i];
    }

    // Printing the array
    cout << "Array: ";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    while (true) {
        cout << "Choose the search method:" << endl;
        cout << "1. Linear Search" << endl;
        cout << "2. Binary Search" << endl;
        cout << "3. Exit" << endl;
        cin >> choice;

        if (choice == 1) {
            // Linear search
            cout << "Enter the number to search in the array: ";
            cin >> k;
            result1 = linear_search(arr, n, k);
            if (result1 == -1) {
                cout << "\nSorry! Element not found" << endl;
            } else {
                cout << k << " is present " << result1 << " times in the array." << endl;
            }
        } 
        else if (choice == 2) {
            // Sorting the array for binary search
            bubbleSort(arr, n);
            cout << "Sorted Array: ";
            for (i = 0; i < n; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;

            // Binary search
            cout << "Enter the number to search in the array: ";
            cin >> m;
            result = binarysearch(arr, 0, n - 1, m);
            if (result == -1) {
                cout << "\nSorry! Element not found" << endl;
            } else {
                cout << "\nElement present at position: " << result + 1 << endl;
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

