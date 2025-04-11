#include <stdio.h>
#include "bubbleSort.h"

void bubbleSort(int a[], int n, int dir)
{
    if (a == NULL) {
        return;
    }

	for (int i = 0; i <= n; i++) {
        for (int j = n; j > i + 1; j--) {
            if (dir == ASC) {
                if (a[j-1] > a[j]) {
                    int temp = a[j - 1];
                    a[j-1] = a[j];
                    a[j] = temp;
                } 
            }
            
            else if (dir == DSC) {
                if (a[j - 1] < a[j]) {
                    int tmp = a[j - 1];
                    a[j - 1] = a[j];
                    a[j] = tmp;
                }
            }
        }
   //PrintArray(a, n, 1);
    }
}



