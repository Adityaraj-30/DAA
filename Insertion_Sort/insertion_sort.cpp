/*Write a program for Insertion sort having 100 different inputs of size varying 30 to 1000,
 Program must record the size of input and no of comparisons done for each size.
 */

#include <iostream>
#include <algorithm>
#include <random>
#include <time.h>

using namespace std;

void getArray(int *a, int size )
{
    unsigned seed = time(0);
    int *temp = new int[970];
    for (int i = 0; i < 970; i++)
        temp[i] = i + 30;
    shuffle(temp, temp + 970, default_random_engine(seed));
    for (int i = 0; i < 100; i++)
        a[i] = temp[i];
}

void insertionSort(int *arr, int size, int *count)
{
    int i, j;
    int key, key1;
    for (i = 1; i < size; i++)
    {
        int temp = 0;
        key = arr[i];
        key1 = count[i];
        j = i - 1;
        count[j]++;
        while (j >= 0 && arr[j] > key)
        {
            if (temp > 0)
                count[j]++;
            arr[j + 1] = arr[j];
            count[j + 1] = count[j];
            j = j - 1;
            temp++;
        }
        arr[j + 1] = key;
        count[j + 1] = key1;
    }
}

void display(int *a, int size)
{
    for (int i = 0; i < size; i++) // Printing sorted array
        cout << a[i] << " ";
    cout << endl;
}

int main() //main
{
    int size;
    cout << "Enter the size of array" << endl;
    cin >> size;
    int *a = new int[size];
    int count[size] = {0};
    getArray(a, size);
    cout << "Input Array: ";
    display(a, size);
    insertionSort(a, size, count);
    cout << "Sorted Array: ";
    display(a, size);
    cout << "\n Number of comparisons for each input:- \n"
         << endl;
    for (int i = 0; i < size; i++)
        cout << "Comparisons for " << a[i] << " = " << count[i] << endl;
    return 0;
} 