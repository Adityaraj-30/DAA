/*Write a program for Merge sort having 100 different inputs of size varying 30 to 1000,
 Program must record the size of input and no of comparisons done for each size.
 */
#include <iostream>
#include <algorithm>
#include <random>
#include <time.h>
#include <iterator>
#include <map>

using namespace std;

map<int, int> ctr;

void getArray(int *a, int n)
{
    unsigned seed = time(0);
    int *temp = new int[970];
    for (int i = 0; i < 970; i++)
        temp[i] = i + 30;
    shuffle(temp, temp + 970, default_random_engine(seed));
    for (int i = 0; i < 100; i++)
        a[i] = temp[i];
}

void merge(int *array, int left, int mid, int right) // Merge Function
{
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;

    int *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            ctr[leftArray[indexOfSubArrayOne]]++;
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            ctr[leftArray[indexOfSubArrayTwo]]++;
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of left[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(int *array, int first, int last) // Divide Function
{
    if (first >= last)
        return;

    int mid = first + (last - first) / 2;
    mergeSort(array, first, mid);
    mergeSort(array, mid + 1, last);
    merge(array, first, mid, last);
}

void display(int *a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of array" << endl;
    cin >> n;
    int *a = new int[n];
    getArray(a, n);
    cout << "\nInput Array: ";
    display(a, n);

    for (int i = 0; i < n; i++)
        ctr.insert(pair<int, int>(a[i], 0));

    mergeSort(a, 0, n - 1);
    cout << "\nSorted Array: ";
    display(a, n);
    cout << "\n Number of comparisons for each input:- \n"
         << endl;
    for (auto itr = ctr.begin(); itr != ctr.end(); ++itr)
    {
        cout << "Comparisons for " << itr->first << " = " << itr->second << endl;
    }
    return 0;
} // main