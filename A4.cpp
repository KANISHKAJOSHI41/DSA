// // BUBBLE SORT WITH NO. COMPARISON AND SWAPS

// #include <iostream>
// using namespace std;

// // Function to perform Bubble Sort
// void bubbleSort(int arr[], int n, int& comparisons, int& swaps) {
//     for (int i = 0; i < n - 1; ++i) {
//         for (int j = 0; j < n - i - 1; ++j) {
//             // Compare adjacent elements
//             comparisons++;
//             if (arr[j] > arr[j + 1]) {
//                 // Swap if out of order
//                 swaps++;
//                 swap(arr[j], arr[j + 1]);
//             }
//         }
//     }
// }

// // Function to print the array
// void printArray(int arr[], int size) {
//     for (int i = 0; i < size; ++i) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
//     int arr[] = {5, 1, 4, 2, 8};
//     int N = sizeof(arr) / sizeof(arr[0]);
//     int comparisons = 0, swaps = 0;

//     bubbleSort(arr, N, comparisons, swaps);

//     cout << "Sorted array: ";
//     printArray(arr, N);
//     cout << "Number of comparisons: " << comparisons << endl;
//     cout << "Number of swaps: " << swaps << endl;

//     return 0;
// }


 // // SELECTION SORT WITH NO. COMPARISON AND SWAPS

// #include<iostream>
// using namespace std;
// void selection_sort(int arr[], int n,int &comparison,int &swaps) {
//   // selection sort
//   for (int i = 0; i < n - 1; i++) {
//     int mini = i;
//     for (int j = i + 1; j < n; j++) {
//         comparison++;
//       if (arr[j] < arr[mini]) {
//         mini = j;
//       }
//     }
//     if(mini !=i){
//         swaps++;
//     int temp = arr[mini];
//     arr[mini] = arr[i];
//     arr[i] = temp;
//     }
//   }

//   cout << "After selection sort: " << "\n";
//   for (int i = 0; i < n; i++) {
//     cout << arr[i] << " ";
//   }
//   cout << "\n";

// }
// int main() {
//   int arr[] = {2,6,5,7,9,1,3,8};

//   int n = sizeof(arr) / sizeof(arr[0]);
//    cout << "Before selection sort: " << "\n";
//    for (int i = 0; i < n; i++) {
//     cout << arr[i] << " ";
//   }
//   cout << "\n";
//   int comparison=0;
//   int swaps=0;
//   selection_sort(arr, n,comparison,swaps);
//   cout<<"number of comparisons "<< comparison  <<endl;
//   cout<<"number of swaps "<< swaps <<endl;
  
//   return 0;
// }

// INSERTION SORTING AND NO. OF COMPARISONS AND SWAPS

#include <iostream>
using namespace std;

void insertionSort(int arr[], int n, int &comparisons, int &swaps) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
            swaps++;
        }
        arr[j + 1] = key;
        swaps++; // One swap for placing the key
    }
}

int main() {
    int arr[] = {10,2,12,8,5,44};
    int n = sizeof(arr) / sizeof(arr[0]);
    int comparisons = 0, swaps = 0;

    insertionSort(arr, n, comparisons, swaps);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;

    return 0;
}