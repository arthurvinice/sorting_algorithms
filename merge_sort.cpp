#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> //For measuring execution time
#include <random> //For generating random numbers
#include <iomanip> //For setprecision

using namespace std;

//Function to merge two sorted subarrays
void merge(vector<int> &v, int low, int high, int mid){
    int i, j, k;
    int c[v.size()]; 
    i = low;
    k = low;
    j = mid + 1;

    while (i <= mid && j <= high){
        if (v[i] < v[j]){
            c[k] = v[i];
            k++;
            i++;
        }
        else{
            c[k] = v[j];
            k++;
            j++;
        }
    }

    while (i <= mid){
        c[k] = v[i];
        k++;
        i++;
    }

    while (j <= high){
        c[k] = v[j];
        k++;
        j++;
    }

    for (i = low; i < k; i++){
        v[i] = c[i];
    }
}

//Function to perform Merge Sort
void mergeSort(vector<int> &v, int low, int high){
    if(low < high){
        int mid = (low + high) / 2;
        mergeSort(v, low, mid);
        mergeSort(v, mid + 1, high);
        merge(v, low, high, mid);
    }
}

int main() {
    //Define vector sizes for testing
    vector<int> sizes = {10, 100, 1000, 10000, 100000,1000000}; //Sizes for testing

    for (int size : sizes) {
        //Generate random vector
        vector<int> vector(size);
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 1000); 

        //Measure execution time
        auto start = chrono::steady_clock::now(); // Start time measurement

        mergeSort(vector, 0, size - 1); //Sort the vector using Merge Sort

        auto end = chrono::steady_clock::now(); //End time measurement

        //Calculate and show execution time in seconds
        double executionTimeSeconds = chrono::duration_cast<chrono::duration<double>>(end - start).count();
        cout << fixed << setprecision(4); 
        cout << "Execution time (size " << size << "): " << executionTimeSeconds << " seconds" << endl;
        cout << endl;
    }

    return 0;
}
