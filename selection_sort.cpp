#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> //For measuring execution time
#include <random> //For generating random numbers
#include <iomanip> //For setprecision

using namespace std;

//Function to perform Selection Sort
void selectionSort(vector<int> &v){
	int min_idx;
	int n=v.size();
	for(int i=0;i<n-1;i++){
		min_idx=i;
		for(int j=i+1;j<n;j++){
			if(v[j]<v[min_idx])
				min_idx=j;
		}
		if(min_idx!=i){
			int temp=v[min_idx];
			v[min_idx]=v[i];
			v[i]=temp;
		}
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

        selectionSort(vector); //Sort the vector using Selection Sort

        auto end = chrono::steady_clock::now(); //End time measurement

        //Showing execution time in seconds 
        double executionTimeSeconds = chrono::duration_cast<chrono::duration<double>>(end - start).count();
        cout << fixed << setprecision(4);
        cout << "Execution time (size " << size << "): " << executionTimeSeconds << " seconds" << endl;
        cout << endl; 
    }
    return 0;
}
