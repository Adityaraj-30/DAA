#include <iostream>
using namespace std;

void bubble_sort(int ar[], int size)
{

    int counter = 1;
    while (counter < size)
    {
        for (int i = 0; i < size - counter; i++)
        {
            if (ar[i] > ar[i + 1])
            {
                int temp = ar[i];
                ar[i] = ar[i + 1];
                ar[i + 1] = temp;
            }
        }
        counter++;
    }
    for (int i = 0; i < size; i++)
    {
        cout << ar[i] << "  ";
    }
}

int main()
{
    int size, ar[size];
    cout << "\nEnter the size of Array:\n";
    cin >> size;
    cout << "\nEnter the elements of array:\n";
    for (int i = 0; i < size; ++i)
    {
        cin >> ar[i];
    }
    cout << "\nThe input array is: ";
    for (int i = 0; i < size; ++i)
    {
        cout << ar[i] << " ";
    }
    cout << "\nThe sorted array is : ";
    bubble_sort(ar, size);
    cout << endl;
    return 0;
}
