#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y);
void quicksort(int array[], int len_array);
void quicksort_recursion(int array[], int low, int high);
int partition(int array[], int low, int high);

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void quicksort(int array[], int len_array) {
    quicksort_recursion(array, 0, len_array - 1);

}

void quicksort_recursion(int array[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(array, low, high);
        quicksort_recursion(array, low, pivot_index - 1);
        quicksort_recursion(array, pivot_index + 1, high);
    }
}

int partition(int array[], int low, int high) {
    int pivot_index = low + (rand() % (high - low));

    if (pivot_index != high) {
        swap(&array[pivot_index], &array[high]);
    }

    int pivot_value = array[high];

    int i = low;

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot_value) {
            swap(&array[i], &array[j]);
            i++;
        }
    }

    swap(&array[i], &array[high]);

    return i;
}

int main() {

    int len_array;
    scanf("%d", &len_array);
    int array[len_array];
    for (int i = 0; i < len_array; i++) {
        scanf("%d", &array[i]);
    }

    quicksort(array, len_array);

    for (int i = 0; i < len_array; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}
