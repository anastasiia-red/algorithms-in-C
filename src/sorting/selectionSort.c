#include <stdio.h>
#include "selectionSort.h"

void selectionSort(int a[], int n, int dir)
{
    if (a == NULL) {
        return;
    }

	for (int i = 1; i <= n; i++) {
        //PrintArray(a, n, 0);
        int minidx = i;

        for (int j = i + 1; j <= n; j++) {
            if (dir == ASC) {
                if (a[j] < a[minidx])
                    minidx = j;
            }
            else if (dir == DSC) {
                if (a[j] > a[minidx])
                    minidx = j;
            }
        }
        int temp = a[i];
        a[i] = a[minidx];
        a[minidx] = temp;   
    }
}