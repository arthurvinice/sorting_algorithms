#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> //For measuring execution time
#include <random> //For generating random numbers
#include <iomanip> //For setprecision

using namespace std;

//Function to perform Shell Sort
void shellSort(vector<int> &v) {
    int n = v.size();
    for (int h = n / 2; h > 0; h /= 2) {
        for (int i = h; i < n; i += 1) {
            int temp = v[i];
            int j;
            for (j = i; j >= h && v[j - h] > temp; j -= h) {
                v[j] = v[j - h];
            }
            v[j] = temp;
        }
    }
}

int main() {
    //Define vector sizes for testing
    vector<int> sizes = {10000, 25000, 50000, 75000, 100000, 200000, 500000}; //Sizes for testing

    for (int size : sizes) {
        //Generate random vector
        vector<int> vector(size);
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 1000); 

        for (int i = 0; i < size; i++) {
            vector[i] = dis(gen);
        }

        //Measure execution time
        auto start = chrono::steady_clock::now(); // Start time measurement

        shellSort(vector); //Sort the vector using Shell Sort

        auto end = chrono::steady_clock::now(); //End time measurement

        //Calculate and show execution time in seconds
        double executionTimeSeconds = chrono::duration_cast<chrono::duration<double>>(end - start).count();
        cout << fixed << setprecision(4); 
        cout << "Execution time (size " << size << "): " << executionTimeSeconds << " seconds" << endl;
        cout << endl;
    }

    return 0;
}
