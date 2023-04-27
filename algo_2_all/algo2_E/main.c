#include <stdio.h>

int main() {

    int len_array;
    scanf("%d", &len_array);

    int i, j;
    int magic_number = 2;

    int array[len_array][magic_number];
    int identify_number;
    int counts_of_points;
    for(i = 0; i < len_array; i++) {
        scanf("%d", &identify_number);
        array[i][0] = identify_number;

        scanf("%d", &counts_of_points);
        array[i][1] = counts_of_points;
    }

    int flag[magic_number];
    for (i = 0; i < len_array; i++) {
        flag[0] = array[i][0];
        flag[1] = array[i][1];
        for (j = i - 1; j >= 0 && (array[j][0] > flag[0]); j--) {
            array[j + 1][0] = array[j][0];
            array[j + 1][1] = array[j][1];
        }
        array[j + 1][0] = flag[0];
        array[j + 1][1] = flag[1];
    }
    for(i = 1; i < len_array; i++) {
        flag[0] = array[i][0];
        flag[1] = array[i][1];
        for (j = i - 1; j >= 0 && (array[j][1] < flag[1]); j--) {
            array[j + 1][0] = array[j][0];
            array[j + 1][1] = array[j][1];
        }
        array[j + 1][0] = flag[0];
        array[j + 1][1] = flag[1];
    }

    for(i = 0; i < len_array; i++) {
        printf("%d %d\n", array[i][0], array[i][1]);
    }

    return 0;
}