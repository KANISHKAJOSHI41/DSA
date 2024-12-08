#include <iostream>
using namespace std;

int main() {
    int arr[10][15]; // Example 2D array
    int baseAddress = 100; // Base address
    int elementSize = sizeof(int); // Size of each element (in bytes)
    int rowIndex = 8; // Row index
    int columnIndex = 6; // Column index

    // Calculate address using row-major order
    int address = baseAddress + elementSize * ((rowIndex - 0) * 15 + (columnIndex - 0));

    cout << "Address of arr[8][6] = " << address << endl;
    return 0;
}
