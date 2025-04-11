#include "insertSort.h"
#include "quickSort.h"
#include "radixSort.h"
#include "selectionSort.h"
#include "llist.h"
#include "lqueue.h"
#include "lstack.h"
#include "hashtable.h"

void demoSorting();
void demoLinkedList();
void demoQueue();
void demoStack();
void demoHashTable();

int main() {
    printf("\n=== AlgoStructs Demo ===\n");
    
    demoSorting();
    demoLinkedList();
    demoQueue();
    demoStack();
    demoHashTable();

    return 0;
}

void demoSorting() {
    int arr[] = {0, 5, 2, 9, 1, 8, 3}; 
    int n = 6;

    printf("\n-- Bubble Sort --\n");
    bubbleSort(arr, n, ASC);

    printf("\n-- Insertion Sort --\n");
    int arr2[] = {0, 5, 2, 9, 1, 8, 3};
    insertSort(arr2, n, ASC);

    printf("\n-- Selection Sort --\n");
    int arr3[] = {0, 5, 2, 9, 1, 8, 3};
    selectionSort(arr3, n, ASC);

    printf("\n-- Heap Sort --\n");
    int arr4[] = {0, 5, 2, 9, 1, 8, 3};
    heapSort(arr4, n);

    printf("\n-- Quick Sort --\n");
    int arr5[] = {0, 5, 2, 9, 1, 8, 3};
    quicksort(arr5, 1, n);

    printf("\n-- Radix Sort --\n");
    char *radixArr[] = {"170", "045", "075", "090", "002", "024", "802"};
    RadixSort(radixArr, 7, 3);
    for (int i = 0; i < 7; i++) printf("%s ", radixArr[i]);
    printf("\n");
}

void demoLinkedList() {
    printf("\n-- Linked List --\n");
    LList list = MakeEmpty(NULL);
    InsertEnd(10, list);
    InsertEnd(20, list);
    InsertBeg(5, list);
    PrintList(list);
    RemoveList(&list);
}

void demoQueue() {
    printf("\n-- Queue --\n");
    LQueue q = CreateQueue();
    Enqueue(1, q);
    Enqueue(2, q);
    Enqueue(3, q);
    PrintQueue(q);
    RemoveQueue(&q);
}

void demoStack() {
    printf("\n-- Stack --\n");
    LStack s = CreateStack();
    Push(10, s);
    Push(20, s);
    Push(30, s);
    PrintStack(s);
    RemoveStack(&s);
}

void demoHashTable() {
    printf("\n-- Hash Table --\n");
    PHASHTABLE ht = HTinit(10);
    HTinsert(ht, "apple");
    HTinsert(ht, "banana");
    HTinsert(ht, "grape");
    HTprint(ht);
    HTdelete(ht, "banana");
    printf("\nAfter delete:\n");
    HTprint(ht);
}
