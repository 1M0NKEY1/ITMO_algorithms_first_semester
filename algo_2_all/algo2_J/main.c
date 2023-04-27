#include <stdio.h>
#include <malloc.h>

void swap_function(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int len_array;
    scanf("%d", &len_array);

    int *parray;
    parray = (int *)malloc(len_array * sizeof(int));

    for (int i = 0; i < len_array; i++) {
        parray[i] = i + 1;
    }

    for (int i = 2; i < len_array; i++) {
        swap_function(&parray[i], &parray[i / 2]);
    }

    for (int i = 0; i < len_array; i++) {
        printf("%d ", parray[i]);
    }

    free(parray);
    return 0;
}
