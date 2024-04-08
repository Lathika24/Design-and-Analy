#include <stdio.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the index of the pivot element
int partition(int arr[], int low, int high) {
    // Choose the pivot
    int pivot = arr[high];
    // Index of smaller element and indicate the right position of the pivot found so far
    int i = (low - 1);

    for (int j = low; j <= high; j++) {
        // If the current element is smaller than the pivot
        if (arr[j] < pivot) {
            // Increment index of smaller element
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The Quicksort function Implementation
void quickSort(int arr[], int low, int high) {
    // When low is less than high
    if (low < high) {
        // pi is the partition return index of the pivot
        int pi = partition(arr, low, high);

        // Recursion Call
        // Smaller elements than the pivot go left, and higher elements go right
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;

    // Get the size of the array from the user
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];

    // Get the array elements from the user
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Function call
    quickSort(arr, 0, n - 1);

    // Print the sorted array
    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
