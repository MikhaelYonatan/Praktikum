#include <stdio.h>
#include "liststatik.h"

int main(){
    ListStatik A, B, Tab;
    int NA, NB;
    boolean asc = TRUE;
    CreateListStatik(&A);
    CreateListStatik(&B);
    CreateListStatik(&Tab);
    readList(&A);
    readList(&B);
    for (int i = 0 ; i < listLength(A) ; i++){
        Tab.contents[i] = A.contents[i];
    } 
    for (int i = 0 ; i < listLength(B) ; i++){
        Tab.contents[i + listLength(A)] = B.contents[i];
    }
    sortList(&Tab, asc);
    printList(Tab);
    printf("\n");
    return 0;
}