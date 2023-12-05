#include <iostream>

using namespace std;

/* function that consider last element as pivot,
place the pivot at its exact position, and place
smaller elements to left of pivot and greater
elements to right of pivot.  */
int swp(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}

int partition(int a[], int start, int end)
{
    int pivot = a[end]; // pivot element is the last elem of the arr

    int i = (start - 1);

    for (int j = start; j <= end - 1; j++) // end-1 because lasts elem is the pivot elem
    {
        // If current element is smaller than the pivot
        if (a[j] < pivot)
        {
            i++; // increment index of smaller element

            swp(a[i], a[j]);
        }
    }

    // after loop
    swp(a[i + 1], a[end]);

    return (i + 1);
}

/* function to implement quick sort */
void quick(int a[], int start, int end) /* a[] = array to be sorted, start = Starting index, end = Ending index */
{
    if (start < end)
    {
        int p = partition(a, start, end); // p is the partitioning index
        quick(a, start, p - 1);
        quick(a, p + 1, end);
    }
}

/* function to print an array */
void printArr(int a[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << a[i] << " ";
}
int main()
{
    int a[] = {23, 8, 28, 13, 18, 26};
    int n = sizeof(a) / sizeof(a[0]);
    cout << "Before sorting array elements are - \n";
    printArr(a, n);
    quick(a, 0, n - 1);
    cout << "\nAfter sorting array elements are - \n";
    printArr(a, n);
    return 0;
}