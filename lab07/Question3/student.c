/*
Question 3: Quick Sort

Description:
Implement quick sort to sort an integer array in ascending order.

Quick sort is a divide-and-conquer algorithm:
1. Choose a pivot element.
2. Partition the array so that elements smaller than or equal to
   the pivot come before it, and elements greater than the pivot
   come after it.
3. Recursively sort the left and right parts.

You should implement:

    void quickSort(int arr[], int size);

You may design your own helper functions.
Suggested helper functions:

    void quickSortHelper(int arr[], int low, int high);
    int partition(int arr[], int low, int high);

For simplicity, you may use the last element as the pivot.

Example:
Input:  [10, 7, 8, 9, 1, 5]
Output: [1, 5, 7, 8, 9, 10]

Notes:
- If the array is empty or has only one element, do nothing.
- The sorting should be done in ascending order.
*/

int partition(int arr[], int low, int high){

    int pivot = arr[high];
    int j = high-1;
    int i = low;

    while (1){

        while (arr[i] < pivot && i < high){
            i++;
        }

        while (arr[j] > pivot && j > low){
            j--;
        }

        if (i >= j){
            break;
        }

        int temp = arr[j];
        arr[j] = arr[i];
        arr[i] = temp;

        i++;
        j--;

    }

    int temp = arr[i];
    arr[i] = arr[high];
    arr[high] = temp;

    return i;

}

void quickSortHelper(int arr[], int low, int high){
    if (low >= high){
    return;
    }

    if (low < high){
        int pivotIndex = partition(arr, low, high);

        quickSortHelper(arr, low, pivotIndex-1);

        quickSortHelper(arr, pivotIndex+1, high);
    }

}

void quickSort(int arr[], int size) {
    // TODO: implement quick sort
    if (!arr || size < 2)
    return;

    quickSortHelper(arr, 0, size-1);
}