# include "stdio.h"

void merge_sort(int array[], int len_array);
void merge_sort_recursion(int array[], int left_side, int right_side);
void merge_sorted_arrays(int array[], int left_side, int middle_side, int right_side);

void merge_sort(int array[], int len_array) {
    merge_sort_recursion(array, 0, len_array - 1);
}

void merge_sort_recursion(int array[], int left_side, int right_side) {

    if (left_side < right_side) {

        int middle_side = left_side + ((right_side - left_side) / 2);

        merge_sort_recursion(array, left_side, middle_side);
        merge_sort_recursion(array, middle_side + 1, right_side);

        merge_sorted_arrays(array, left_side, middle_side, right_side);
    }
}

void merge_sorted_arrays(int array[], int left_side, int middle_side, int right_side) {

    int left_side_length = middle_side - left_side + 1;
    int right_side_length = right_side - middle_side;

    int temp_left[left_side_length];
    int temp_right[right_side_length];

    int i, j, k;

    for (i = 0; i < left_side_length; i++)
        temp_left[i] = array[left_side + i];


    for (i = 0; i < right_side_length; i++)
        temp_right[i] = array[middle_side + 1 + i];


    for (i = 0, j = 0, k = left_side; k <= right_side; k++) {
        if ((i < left_side_length) && (j >= right_side_length || temp_left[i] <= temp_right[j])) {
            array[k] = temp_left[i];
            i++;
        } else {
            array[k] = temp_right[j];
            j++;
        }
    }
}

int main() {

    int len_array;
    scanf("%d", &len_array);
    int array[len_array];
    for (int i = 0; i < len_array; i++) {
        scanf("%d", &array[i]);
    }

    merge_sort(array, len_array);

    for (int i = 0; i < len_array; i++) {
        printf("%d ", array[i]);
    }

    return 0;
}

