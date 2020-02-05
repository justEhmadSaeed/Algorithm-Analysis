
// Libraries to be added

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <chrono>
#include <time.h>
#include <fstream>
using namespace std;

// Function Prototypes

void InsertionSort(int array[], int start, int end);
void RandomArray(int array[], int size);

int main()
{
	int size;
	cout << "Enter the Size of Array: ";
	cin >> size;
	int *A = new int[size];

	// To generate random Numbers and store them

	srand(time(NULL));
	RandomArray(A, size);

	// Code to call InsertionSort and measure time duration

	auto start = chrono::high_resolution_clock::now();
	InsertionSort(A, 0, size - 1);
	auto end = chrono::high_resolution_clock::now();
	double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

	// Code to calculate the time duration

	time_taken *= 1e-9;
	cout << "\n Time taken by the insertion Sort, with " << size << " size of Array is: ";
	cout << fixed << time_taken << setprecision(9) << " seconds" << endl;

	// Code to Save sorted array in csv file

	ofstream OutData;
	OutData.open("SortedInsertionSort.csv");
	for (int i = 0; i < size; i++)
		OutData << A[i] << endl;

	delete[] A;
}

// $$$ Functions Definitions $$$

// InsertionSort Iterative Function
void InsertionSort(int arr[], int startIndex, int endIndex)
{

	int i, key, j;
	for (i = startIndex + 1; i <= endIndex; i++)
	{
		key = arr[i];
		j = i - 1;
		// To place the element in the sorted array
		while (j >= startIndex && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

// RandomArray Function to fill the array with random numbers
void RandomArray(int array[], int size)
{

	for (int i = 0; i < size; i++)
		array[i] = rand();
}
