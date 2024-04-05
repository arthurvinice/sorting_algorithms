#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> // For measuring execution time
#include <random> // For generating random numbers
#include <iomanip> // For setprecision

using namespace std;

// Function to swap two items
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array for Quick Sort
int partition(vector<int> &v, int low, int high){
    int pivot = v[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (v[j] < pivot) {
            i++;
            swap(&v[i], &v[j]);
        }
    }
    swap(&v[i + 1], &v[high]);
    return (i + 1);
}

// Function to perform Quick Sort
void quickSort(vector<int> &v, int low, int high){
    if (low < high) { 
        int pi = partition(v, low, high);
        quickSort(v, low, pi - 1);
        quickSort(v, pi + 1, high);
    }
}

int main() {
    // Defining vector sizes for testing
    vector<int> sizes = {1000, 10000, 25000, 50000, 75000, 100000}; // Sizes for testing

    for (int size : sizes) {
        // Generate random vector
        vector<int> vector(size);
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 1000);

        for (int i = 0; i < size; i++) {
            vector[i] = dis(gen);
        }

        // Measure execution time
        auto start = chrono::steady_clock::now(); //Start time measurement

        quickSort(vector, 0, size - 1); //Sort the vector using Quick Sort

        auto end = chrono::steady_clock::now(); //End time measurement

        // Calculate and show execution time in seconds
        double executionTimeSeconds = chrono::duration_cast<chrono::duration<double>>(end - start).count();
        cout << fixed << setprecision(4); 
        cout << "Execution time (size " << size << "): " << executionTimeSeconds << " seconds" << endl;
        cout << endl; 
    }

    return 0;
}
