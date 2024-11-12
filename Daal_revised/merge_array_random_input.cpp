#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int d = 1, n;

void printArray(int arr[], int size)  // Printing the array
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void printArray1(int arr[], int size) {
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

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];    // Create temp arrays
    
    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    
    // Merge the temp arrays back into arr[l..r]
    int i = 0;    // Initial index of first subarray
    int j = 0;    // Initial index of second subarray
    int k = l;    // Initial index of merged subarray
    
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
    
    // Copy the remaining elements of L[], if there are any
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copy the remaining elements of R[], if there are any
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
    
    cout << "\nPass " << d << ": ";
    d++;
    printArray(arr, r + 1);
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;   // m = middle value; l = left; r = right
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        // Merge the sorted halves
        merge(arr, l, m, r);
    }
}

int main()
{
    srand(time(0)); // Seed for random number generation
    cout << "Enter the number of elements you want to sort: ";
    cin >> n;
    
    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1; // Random values between 1 and 100
    }

    cout << "Initial array: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "\nSorted array without repetition: ";
    printArray1(arr, n);

    return 0;
}
