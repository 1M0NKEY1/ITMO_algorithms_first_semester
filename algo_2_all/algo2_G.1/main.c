# include "stdio.h"
# include <stdbool.h>

void merge_sort(int array[], int len_array);
void merge_sort_recursion(int array[], int left_side, int right_side);
void merge_sorted_arrays(int array[], int left_side, int middle_side, int right_side);
void sorted_and_compared_arrays(int array1[], int array2[], int len_array1, int len_array2);
void exclusion_of_elements(int array[], int len_array);


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

void sorted_and_compared_arrays (int array1[], int array2[], int len_array1, int len_array2) {
    int i = 0;
    bool counter = 1;

    while ((i < len_array1) && (i < len_array2)) {
        if (array1[i] != array2[i]) {
            counter = 0;
        }
        i++;
    }

    if(counter == 1) {
        printf("YES");
    } else {
        printf("NO");
    }
}

void exclusion_of_elements(int array[], int len_array) {
    int i = 1;
    int j = 1;
    int temp[len_array];

    temp[0] = array[0];

    while ((i < len_array) && (j < len_array)) {
        if (array[i] != temp[j - 1]) {
            temp[j] = array[i];
            i++;
            j++;
        } else {
            i++;
        }
    }

    temp[j] = 0;

    for (i = 0; i < j; i++) {
        array[i] = temp[i];
    }
}

int main() {

    int len_array1;
    scanf("%d", &len_array1);
    int array1[len_array1];
    for (int i = 0; i < len_array1; i++) {
        scanf("%d", &array1[i]);
    }

    int len_array2;
    scanf("%d", &len_array2);
    int array2[len_array2];
    for (int i = 0; i < len_array2; i++) {
        scanf("%d", &array2[i]);
    }

    merge_sort(array1, len_array1);
    merge_sort(array2, len_array2);

    exclusion_of_elements(array1, len_array1);
    exclusion_of_elements(array2, len_array2);

    sorted_and_compared_arrays(array1, array2, len_array1, len_array2);
    return 0;
}

