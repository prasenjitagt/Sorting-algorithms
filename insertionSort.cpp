#include <iostream>
using namespace std;

void print(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void insertion(int *a, int n)
{
    for (int i = 1; i < n; i++)
    {
        int crr = a[i];
        int j = i - 1;
        while (a[j] > crr && j >= 0)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = crr;
    }
}

int main()
{

    int arr[5] = {89, 4, 1, 3, 6};

    cout << "Before Sorting" << endl;
    print(arr, 5);

    cout << "After Sorting" << endl;
    insertion(arr, 5);
    print(arr, 5);
}
