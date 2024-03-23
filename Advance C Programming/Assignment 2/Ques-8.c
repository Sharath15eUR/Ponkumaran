#include <stdio.h>
int isSubset(int arr1[], int m, int arr2[], int n) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (arr2[i] == arr1[j])
                break;
        }
        if (j == m)
            return 0;
    }
    return 1;
}

int main() {
    int arr1[] = {11, 1, 13, 21, 3, 7};
    int arr2[] = {11, 3, 7, 1};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    if (isSubset(arr1, m, arr2, n))
        printf("arr2[] is a subset of arr1[]\n");
    else
        printf("arr2[] is not a subset of arr1[]\n");

    int arr3[] = {10, 5, 2, 23, 19};
    int arr4[] = {19, 5, 3};
    m = sizeof(arr3) / sizeof(arr3[0]);
    n = sizeof(arr4) / sizeof(arr4[0]);
    if (isSubset(arr3, m, arr4, n))
        printf("arr4[] is a subset of arr3[]\n");
    else
        printf("arr4[] is not a subset of arr3[]\n");
    return 0;
}
