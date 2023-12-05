#include <iostream>
#include <vector>

using namespace std;

// Function to find the maximum number to determine the number of digits
int getMax(vector<int> &arr)
{
    int max = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Using counting sort to sort the elements based on significant places
void countingSort(vector<int> &arr, int exp)
{
    const int n = arr.size();
    vector<int> output(n);
    vector<int> count(10, 0);

    // Count occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains the actual
    // position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] contains sorted numbers
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Main function to implement radix sort
void radixSort(vector<int> &arr)
{
    int max = getMax(arr);

    // Apply counting sort to sort elements based on place value.
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(arr, exp);
    }
}

// Function to print an array
void printArray(const vector<int> &arr)
{
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}

// Driver code
int main()
{
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    cout << "Original array: ";
    printArray(arr);

    radixSort(arr);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}