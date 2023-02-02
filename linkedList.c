#include <stdio.h>
#include <stdlib.h>
/**
 * default Node, add data as needed
*/
struct Node{
    int data;
    struct Node* next;
};

/**
 * print off all of the elements of the list
*/
void LLprint(struct Node* n) {
    while(n != NULL){
    printf("%d, ", n -> data);
    n = n -> next;
   }
   printf("\n");
}

/**
* Needed to start a list
*/
struct Node* LLinit(int n){
    struct Node* head = NULL;
    head = (struct Node*) malloc(sizeof(struct Node));
    // input default data here
    head -> data = n;
    head -> next = NULL;
    return head;
}

/**
 * Adds to the end of the list
*/
void LLadd(struct Node* head, int n){
    struct Node* curr = head;
    while (curr -> next != NULL){
       curr = curr -> next;
    }
    struct Node* new = (struct Node*) malloc(sizeof(struct Node));
       curr -> next = new;
       new -> data = n;
       new -> next = NULL;
       printf("added  %d\n", n);
    
}
/**
 * Gets the nth element
*/
struct Node* LLget(struct Node* head, int n){
    struct Node* curr = head;
    for(int i = 0; i < n; i++){
        curr = curr -> next;
    }
    return curr;
}

/**
 * Puts a new element at index n
*/
void LLinsert(struct Node* head, int n, int d){
    struct Node* curr = head;
    for(int i = 0; i < n - 1; i++){
        curr = curr -> next;
    }
    struct Node* new = (struct Node*) malloc(sizeof(struct Node));
       new -> next = curr -> next;
       curr -> next = new;
       new -> data = d;
}

int main(){
    struct Node* list = LLinit(5);
    LLadd(list, 4);
    LLadd(list, 3);
    LLadd(list, 2);
    LLadd(list, 1);
    LLprint(list);
    printf("%d\n", LLget(list, 2) -> data);
    LLinsert(list, 2, 10);
    LLprint(list);
}