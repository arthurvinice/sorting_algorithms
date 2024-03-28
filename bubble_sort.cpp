#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> // For measuring execution time
#include <random> // For generating random numbers
#include <iomanip> // For setprecision

using namespace std;

// Function to perform Bubble Sort
void bubbleSort(vector<int> &v) {
    int n = v.size();
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(v[j] > v[j + 1]) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int main() {
    // Defining vector sizes for testing
    vector<int> sizes = {10, 100, 1000, 10000, 100000}; // Sizes for testing

    for(int size : sizes) {
        // Generating a random vector
        vector<int> vector(size);
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 1000);

        for(int i = 0; i < size; i++) {
            vector[i] = dis(gen);
        }

        // Measure execution time
        auto start = chrono::steady_clock::now(); // Start time measurement

        bubbleSort(vector); // Sort the vector using Bubble Sort

        auto end = chrono::steady_clock::now(); // End time measurement

        // Showing execution time in seconds 
        double executionTimeSeconds = chrono::duration_cast<chrono::duration<double>>(end - start).count();
        cout << fixed << setprecision(4); 
        cout << "Execution time (size " << size << "): " << executionTimeSeconds << " seconds" << endl;

        cout << endl; 
    }
    return 0;
}
