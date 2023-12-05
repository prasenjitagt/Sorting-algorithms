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

void merge(int *a, int s, int mid, int e)
{
    int s1 = mid - s + 1;
    int s2 = e - mid;

    int arr1[s1], arr2[s2];

    for (int i = 0; i < s1; i++)
    {
        arr1[i] = a[s + i];
    }

    for (int i = 0; i < s2; i++)
    {
        arr2[i] = a[mid + 1 + i];
    }

    int p1 = 0;
    int p2 = 0;
    int k = s;

    while (p1 < s1 && p2 < s2)
    {
        if (arr1[p1] < arr2[p2])
        {
            a[k] = arr1[p1];
            k++;
            p1++;
        }
        else
        {
            a[k] = arr2[p2];
            k++;
            p2++;
        }
    }

    while (p1 < s1)
    {
        a[k] = arr1[p1];
        k++;
        p1++;
    }

    while (p2 < s2)
    {
        a[k] = arr2[p2];
        k++;
        p2++;
    }
}

void mergeDiv(int *a, int s, int e)
{

    if (s < e)
    {
        int mid = s + (e - s) / 2;
        mergeDiv(a, s, mid);
        mergeDiv(a, mid + 1, e);

        merge(a, s, mid, e);
    }
}

int main()
{

    int arr[5] = {1, 42, 89, 8, 6};

    cout << "Before Sorting" << endl;
    print(arr, 5);

    mergeDiv(arr, 0, 5);

    cout << "After Sorting" << endl;
    print(arr, 5);
}
