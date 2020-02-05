#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <time.h>
#include <fstream>
using namespace std;
void InsertionSort(int array[], int start, int end);
void RandomArray(int array[], int size);
int main() {
	int size;
	cout << "Enter the Size of Array: ";
	cin >> size;
	int* A = new int[size];
	srand(time(NULL));
	RandomArray(A, size);

	/*cout << "\n Numbers before Sorting\n to print them, ";
	system("pause");
	for (int i = 0; i < size; i++)
		cout << A[i] << endl;
*/
	clock_t start, end;
	start = clock();
	InsertionSort(A, 0, size - 1);
	end = clock();
	double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "\n Time taken by the insertion Sort,\nwith " << size << " size of Array is: ";
	cout << fixed << time_taken << setprecision(7)<<" seconds"<<endl;

	ofstream OutData;
	OutData.open("SortedInsertionSort.csv");
	for (int i = 0; i < size; i++)
		OutData << A[i] << endl;
	/*cout << "\n\n Numbers after Sorting\n To print them, ";
	system("pause");
	for (int i = 0; i < size; i++)
		cout << A[i] << endl;*/
	delete[] A;
}

// $$$ Functions Definitions $$$

// InsertionSort Iterative Function
void InsertionSort(int arr[], int startIndex, int endIndex) {

	int i, key, j;
	for (i = 1; i <= endIndex; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}
// RandomArray Function to fill the array with random numbers
void RandomArray(int array[], int size) {

	for (int i = 0; i < size; i++)
		array[i] = rand();

}