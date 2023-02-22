#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct List{
    struct Node* head;
    struct Node* tail;
    int length;
};

struct List* CDLinit(int n){
    struct Node* head = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));
    head->data = n;
    head->next = NULL;
    struct List* list = NULL;
    list = (struct List*)malloc(sizeof(struct List));
    list->head = head;
    list->tail = head;
    list->length = 1;
}

void CDLaddtail(struct List* list, int n){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new -> data = n;
    new -> next = NULL;
    new -> prev = list -> tail;
    list -> tail -> next = new;
    list -> tail = new;
    list -> length++;
}

void CDLaddhead(struct List* list, int n){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new -> data = n;
    new -> next = list -> head;
    new -> prev = NULL;
    list -> head -> prev = new;
    list -> head = new;
    list -> length++;
}

void CDLprintfwd(struct List* list){
    struct Node* curr = list -> head;
    while (curr != NULL){
        printf("%d, ", curr -> data);
        curr = curr -> next;
    }
    printf("\n");
}

void CDLpoptail(struct List* list){
    struct Node* curr = list -> tail;
    curr ->prev ->next = NULL;
    list -> tail = curr->prev;
    list -> length--;
    free(curr);
}

void CDLpophead(struct List* list){
    struct Node* curr = list -> head;
    curr -> next -> prev = NULL;
    list -> head = curr -> next;
    list -> length--;
    free(curr);
}

void CDLremovehead(struct List* list, int index){
    struct Node* curr = list -> head;
    for(int i = 0; i < index; i++){

    }
}



int main(){
    struct List* list = CDLinit(1);
    CDLaddtail(list, 2);
    CDLaddtail(list, 3);
    CDLaddhead(list, 0);
    CDLprintfwd(list);
    CDLpophead(list);
    CDLpoptail(list);
    CDLprintfwd(list);

}