#include <stdio.h>
#include "insertSort.h"

void insertSort(int *A, int n, int dir)
{
    if (A == NULL) {
        return;
    }

	for (int i = 1; i < n + 1; i++) {
        int value = A[i];
        int j = i - 1;
        
        if (dir == ASC) {
            while (j >= 1 && A[j] > value) {
                A[j + 1] = A[j];
                j--;
            }
        }

        else if (dir == DSC) {
            while (j >= 1 && A[j] < value) {
                A[j + 1] = A[j];
                j--;
            }
        }

        A[j + 1] = value;
        //PrintArray(A, n, 0);
    }
}