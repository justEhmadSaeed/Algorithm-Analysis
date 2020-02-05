#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <math.h>
#include <time.h>
#include <fstream>

using namespace std;
void MergeSort(int array[], int start, int end);
void Merge(int array[], int p, int q, int r);
void RandomArray(int array[], int size);
int main()
{
	int size;
	cout << "Enter the Size of Array: ";
	cin >> size;
	int *A = new int[size];
	srand(time(NULL));
	RandomArray(A, size);

	/*cout << "\n Numbers before Sorting\n to print them, ";
	system("pause");
	for (int i = 0; i < size; i++)
		cout << A[i] << endl;
*/
	clock_t start, end;
	cout << "check1\n";
	start = clock();
	MergeSort(A, 0, size - 1);
	end = clock();
	cout << "check2\n";
	float time_taken = float(end - start) / float(CLOCKS_PER_SEC);
	cout << "\n Time taken by the Merge Sort,\nwith " << size << " size of Array is: ";
	cout << fixed << time_taken << setprecision(7) << " seconds" << endl;

	ofstream OutData;
	OutData.open("SortedMergeSort.csv");
	for (int i = 0; i < size; i++)
		OutData << A[i] << endl;

	/*cout << "\n\n Numbers after Sorting\n To print them, ";
	system("pause");
	for (int i = 0; i < size; i++)
		cout << A[i] << endl;*/

	delete[] A;
	return 0;
}
// $$$ Functions Definitions $$$

// MergeSort Iterative Function
void MergeSort(int arr[], int startIndex, int endIndex)
{
	if (startIndex < endIndex)
	{
		int q = floor((startIndex + endIndex) / 2);
		MergeSort(arr, startIndex, q);
		MergeSort(arr, q + 1, endIndex);
		Merge(arr, startIndex, q, endIndex);
	}
}
void Merge(int arr[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;

	int *Left = new int[n1 + 1];
	int *Right = new int[n2 + 1];

	for (int i = 0; i < n1; i++)
		Left[i] = arr[p + i];
	for (int i = 0; i < n2; i++)
		Right[i] = arr[q + 1 + i];

	Left[n1] = 147483647;
	Right[n2] = 147483647;

	int i = 0, j = 0, k = p;
	for (k; k <= r; ++k)
	{
		if (Left[i] <= Right[j])
		{
			arr[k] = Left[i];
			++i;
		}
		else
		{
			arr[k] = Right[j];
			++j;
		}
	}
	delete[] Left;
	delete[] Right;
}
// RandomArray Function to fill the array with random numbers
void RandomArray(int array[], int size)
{

	for (int i = 0; i < size; i++)
		array[i] = rand();
}