#include "llist.h"
#include "err.h"
#include <stdlib.h>

struct Node
{
    PNode	Next;
    TElem	Elem;
};

struct LnkList
{
    PNode	First;
    PNode	Last;
};


LList MakeEmpty(LList L)
{
    LList PL;
    if(L != NULL) RemoveList(&L);
    PL = malloc(sizeof(struct LnkList));
    if(PL == NULL) Error("MakeEmpty: out of memory!");
    PL->First = NULL;
    PL->Last = NULL;
    return PL;
}


void RemoveList(LList *PL)
{
    PNode T,P;
    if(PL == NULL) Error("RemoveList: incorrect pointer!");
    LList L = *PL;
    if(L == NULL) return;
    P = L->First;
    while(P != NULL){
        T = P->Next;
        free(P);
        P = T;
    }
    free(L);
    *PL = NULL;
}


void Delete( TElem X, LList L )
{
    PNode P,C;
    if(L == NULL) Error("Delete: incorrect list!");
    if(Member(X,L)){
        P = L->First;
        C = L->First;
        while(C != NULL){
            if(C->Elem == X){
                if(C->Next == NULL) L->Last = P;                
                if(C->Next == NULL && P == C) L->Last = NULL;  
                if(P == C) L->First = C->Next;                  
                else P->Next = C->Next;
                free(C);
                break;
            }
            P = C;
            C = C->Next;
        }
    }
}


int IsEmpty(LList L)
{
    if(L == NULL) Error("IsEmpty: incorrect list!");
    return L->First == NULL;
}


int IsLast(PNode P)
{
    if(P == NULL) Error( "IsLast: incorrect pointer on input!" );
    return P->Next == NULL;
}


PNode Member( TElem X, LList L )
{
    PNode P;
    if(L == NULL) Error("Member: incorrect list!");
    P = L->First;
    while(P != NULL){
        if(P->Elem == X) break;
        P = P->Next;
    }
    return P;
}


void InsertBeg( TElem X, LList L )
{
    PNode T;
    if(L == NULL) Error("InsertBeg: incorrect list!");
    T = malloc(sizeof(struct Node));
    if(T == NULL) Error("InsertBeg: out of memory!");
    T->Elem = X;
    T->Next = L->First;
    if(IsEmpty(L)) L->Last = T;
    L->First = T;
}


void InsertEnd( TElem X, LList L )
{
    PNode T;
    if(L == NULL) Error("InsertEnd: incorrect list!");
    T = malloc(sizeof(struct Node));
    if(T == NULL) Error("InsertEnd: out of memory!");
    T->Elem = X;
    T->Next = NULL;
    if(IsEmpty(L)) {
        L->First = T;
        L->Last = T;
    }
    else {
        L->Last->Next = T;
        L->Last = T;
    }
}


PNode First( LList L )
{
    if(L == NULL) Error("First: incorrect list!");
    return L->First;
}


PNode Next( PNode P )
{
    if(P == NULL) Error( "Next: incorrect pointer on input!" );
    return P->Next;
}


LList Head( LList L )
{
    return L;
}


TElem Get( PNode P )
{
    if(P == NULL) Error( "Get: incorrect pointer on input!" );
    return P->Elem;
}


void PrintList( LList L )
{
    if(L == NULL) {
        printf("PrintList: incorrect list!\n");
        return;
    }
    PNode P = First( L );
    if(IsEmpty( L )) printf( "Empty list" );
    else
    {
        while(P != NULL)
        {
            printf("%d ", Get(P));
            P = Next(P);
        }
    }
}


void FastCat( LList L1, LList L2 )
{
    if (L1 == NULL || L2 == NULL) {
        Error ("FastCat: incorrect list!");
        return;
    }

    if (IsEmpty(L1)){
        L1->First = L2->First;
        L1->Last = L2->Last;

        L2->First = NULL;
        L2->Last = NULL;
        return;
    }

    PNode LastL1 = L1->Last;
    LastL1->Next = L2->First;
    L1->Last = L2->Last;

    L2->First = NULL;
    L2->Last = NULL;
}


LList FreshCat( LList L1, LList L2 )
{
    if (L1 == NULL || L2 == NULL){
        Error("FreshCat: incorrect list!");
        return NULL;
    }

    LList NewList = MakeEmpty( NULL );

    if (IsEmpty(L1) && IsEmpty(L2)){
        return NewList;
    }

    if (!IsEmpty(L1)){
        PNode T = L1->First;
        while (T != NULL){
            InsertEnd(T->Elem, NewList);
            T = T->Next;
        }
    }

    PNode T = L2->First;
        while (T != NULL){
            InsertEnd(T->Elem, NewList);
            T = T->Next;
        }

    return NewList;
}


LList Cut( LList L, PNode P )
{
    if (L == NULL || P == NULL){
        Error("Cut: incorrect list or node!");
        return NULL;
    }

    if (IsEmpty(L)){
        return NULL;
    }

    LList NewList = MakeEmpty( NULL );

    PNode T = P->Next;
        while (T != NULL){
            InsertEnd(T->Elem, NewList);
            T = T->Next;
        }

    L->Last = P;
    L->Last->Next = NULL;

    return NewList;

}
