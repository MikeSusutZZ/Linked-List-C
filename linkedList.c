#include <stdio.h>
#include <stdlib.h>
/**
 * default Node, add data as needed
 */
struct Node
{
    int data;
    struct Node *next;
};

/**
 * print off all of the elements of the list
 */
void LLprint(struct Node *n)
{
    while (n != NULL)
    {
        printf("%d, ", n->data);
        n = n->next;
    }
    printf("\n");
}

/**
 * Needed to start a list
 */
struct Node *LLinit(int n)
{
    struct Node *head = NULL;
    head = (struct Node *)malloc(sizeof(struct Node));
    // input default data here
    head->data = n;
    head->next = NULL;
    return head;
}

/**
 * Adds to the end of the list
 */
void LLadd(struct Node *head, int n)
{
    struct Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    curr->next = new;
    new->data = n;
    new->next = NULL;
    //printf("added  %d\n", n);
}
/**
 * Gets the nth element
 */
struct Node *LLget(struct Node *head, int n)
{
    struct Node *curr = head;
    for (int i = 0; i < n; i++)
    {
        curr = curr->next;
    }
    return curr;
}

/**
 * Puts a new element at index n
 */
void LLinsert(struct Node *head, int n, int d)
{
    struct Node *curr = head;
    for (int i = 0; i < n - 1; i++)
    {
        curr = curr->next;
    }
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    new->next = curr->next;
    curr->next = new;
    new->data = d;
}

/**
 * removes the nth element. 
 * If you are removing the head,
 * you must write as: head = LLremove(head, 0);
 * so the head is set to the correct pointer
 */
struct Node *LLremove(struct Node *head, int n)
{

    if (n != 0)
    {
        struct Node *curr = head;
        for (int i = 0; i < n - 1; i++)
        {
            curr = curr->next;
        }
        struct Node *pop = curr->next;
        curr->next = curr->next->next;
        free(pop);
        return head;
    }
    else
    {
        return head->next;
        free(head);
    }
}

struct Node* LLdup(struct Node* head){
    struct Node* new = LLinit(head -> data);
    struct Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
        LLadd(new, curr -> data);
    }
    return new;

}

int main()
{
    struct Node *list = LLinit(5);
    LLadd(list, 4);
    LLadd(list, 3);
    LLadd(list, 2);
    LLadd(list, 1);
    LLprint(list);
    printf("%d\n", LLget(list, 2)->data);
    LLinsert(list, 2, 10);
    list = LLremove(list, 0);
    LLremove(list, 4);
    LLprint(list);
    struct Node* copy = LLdup(list);
    LLprint(copy);
}