#include <iostream>
#include <ctime>
using namespace std;

int partition(int arr[], int l, int m)
{
    int pivot = arr[m];
    int i = l - 1;

    for (int j = l; j < m; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i + 1], arr[m]);
    return i + 1;
}

int Random_partition(int arr[], int p, int q)
{

    srand(time(0));
    int random = p + rand() % (q - p);
    swap(arr[random], arr[q]);
    return partition(arr, p, q);
}

int RandomnizedSelect(int arr[], int l, int m, int k)
{ // k is the kth element to be returned

    int p, pos;

    p = Random_partition(arr, l, m);
    pos = p - l + 1;

    if (pos == k)
    {
        return arr[p];
    }
    else if (pos > k)
    {
        return RandomnizedSelect(arr, l, p - 1, k);
    }
    else if (pos < k)
    {
        return RandomnizedSelect(arr, p + 1, m, k - pos);
    }
    return 1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << RandomnizedSelect(arr, 0, 4, 4);
    cout << endl;

    return 0;
}