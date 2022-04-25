/*Write a program for Quick sort having 100 different inputs of size varying 30 to 1000,
 Program must record the size of input and no of comparisons done for each size.
 */

#include <iostream>
#include <algorithm>
#include <random>
#include <time.h>

using namespace std;

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

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *a, int low, int high, int *count) // places all smaller (smaller than pivot) to left of pivot and all greater elements to right of pivot
{
    int p = a[high];
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far

    for (int j = low; j <= high - 1; j++)
    {
        count[j]++;
        if (a[j] < p)
        {
            i++;
            swap(&a[i], &a[j]);
            swap(&count[i], &count[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

void quickSort(int *a, int low, int high, int *count)
{
    if (low < high)
    {
        int pi = partition(a, low, high, count);

        quickSort(a, low, pi - 1, count);
        quickSort(a, pi + 1, high, count);
    }
}

void display(int *a, int n)
{
    for (int i = 0; i < n; i++) // Printing sorted array
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the size of array" << endl;
    cin >> n;
    int *a = new int[n];
    int count[n] = {0};
    getArray(a, n);
    cout << "\nInput Array: ";
    display(a, n);
    quickSort(a, 0, n - 1, count);
    cout << "\nSorted Array: ";
    display(a, n);
    cout << "\n Number of comparisons for each input:- \n"
         << endl;
    for (int i = 0; i < n; i++)
        cout << "Comparisons for " << a[i] << " = " << count[i] << endl;
    return 0;
} // main