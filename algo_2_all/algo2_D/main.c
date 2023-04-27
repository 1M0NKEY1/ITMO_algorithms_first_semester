#include <stdio.h>
#include <stdbool.h>

int main() {
    int len_array;
    scanf("%d", &len_array);

    int element;
    int i, j, k;

    int array[len_array];
    for(i = 0; i < len_array; i++) {
        scanf("%d", &element);
        array[i] = element;
    }

    int flag;
    bool counter;

    for (i = 1; i < len_array; i++) {
        flag = array[i];
        counter = 0;

        for(j = i - 1; j >= 0 && array[j] > flag; j--) {
            array[j + 1] = array[j];
            counter = 1;
        }

        array[j + 1] = flag;

        if (counter == 1) {
            for(k = 0; k < len_array; k++) {
                printf("%d ", array[k]);

                if (k == len_array - 1) {
                    printf("\n");
                }
            }
        }
    }

    return 0;
}
