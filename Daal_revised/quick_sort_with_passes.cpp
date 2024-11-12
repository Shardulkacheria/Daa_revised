#include <iostream>
#include <string>
using namespace std;

void printArray(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Not printing repeating elements
void printArray1(char arr[], int size) {
    if (size > 0) {
        cout << arr[0] << " ";
    }
    for (int i = 1; i < size; i++) {
        if (arr[i] != arr[i - 1]) {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int partition(char arr[], int low, int high, int &pass) {
    char pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    pass++;
    cout << "Pass " << pass << " (Pivot: " << pivot << "): ";
    printArray(arr, high - low + 1);
    return (i + 1);
}

void quickSort(char arr[], int low, int high, int &pass) {
    if (low < high) {
        int pi = partition(arr, low, high, pass);

        quickSort(arr, low, pi - 1, pass);
        quickSort(arr, pi + 1, high, pass);
    }
}

int main() {
    string input;

    cout << "Enter the string you want to sort: ";
    cin >> input;

    int n = input.length();
    char arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = input[i];
    }

    cout << "Initial array: ";
    printArray(arr, n);

    int pass = 0;
    quickSort(arr, 0, n - 1, pass);

    cout << "Sorted array without repetition: ";
    printArray1(arr, n);

    return 0;
}

