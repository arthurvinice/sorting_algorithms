#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> // For measuring execution time
#include <random> // For generating random numbers
#include <iomanip> // For setprecision

using namespace std;

//Function to perform Insertion Sort
void insertionSort(vector<int> &v) {
    int n = v.size();
    for (int i = 1; i < n; i++) {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = key;
    }
}

int main() {
    //Defining vector sizes for testing
    vector<int> sizes = {1000, 10000, 25000, 50000, 75000, 100000}; //Sizes for testing

    for (int size : sizes) {
        //Generating a random vector
        vector<int> vector(size);
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 1000);

        for (int i = 0; i < size; i++) {
            vector[i] = dis(gen);
        }

        //Measure execution time
        auto start = chrono::steady_clock::now(); //Start time measurement

        insertionSort(vector); //Sort the vector using Insertion Sort

        auto end = chrono::steady_clock::now(); //End time measurement

        //Showing execution time in seconds 
        double executionTimeSeconds = chrono::duration_cast<chrono::duration<double>>(end - start).count();
        cout << fixed << setprecision(4);
        cout << "Execution time (size " << size << "): " << executionTimeSeconds << " seconds" << endl;
        cout << endl; 
    }
    return 0;
}
