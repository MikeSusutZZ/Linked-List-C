#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * default Node, add data as needed
 */
struct Node
{
    // Insert data
    int data;
    struct Node *next;
};

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
    // Insert data here
    new->data = n;

    new->next = NULL;
}

/**
 * Removes the last element
 */
void LLpop(struct Node *head)
{
    struct Node *curr = head;
    while (curr->next != NULL && curr->next->next != NULL)
    {
        curr = curr->next;
    }
    struct Node *pop = curr->next;
    curr->next = NULL;
    // printf("LLpop free=%p\n", pop);
    free(pop);
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
    // Insert data
    new->data = d;
}

/**
 * Removes the nth element
 * must be entered as 'LLremove(&head)'
 */
void LLremove(struct Node **head, int n)
{
    if (n != 0)
    {
        struct Node *curr = *head;
        for (int i = 0; i < n - 1; i++)
        {
            curr = curr->next;
        }
        struct Node *pop = curr->next;
        curr->next = curr->next->next;

        free(pop);
    }
    else
    {
        struct Node *hold = *head;
        *head = (*head)->next;
        free(hold);
    }
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
 * print off all of the elements of the list
 */
void LLprint(struct Node *n)
{
    while (n != NULL)
    {
        // Insert data
        printf("%d, ", n->data);
        n = n->next;
    }
    printf("\n");
}

/**
 * Print off all elements of the list as a char, all together 
*/
void LLprintc(struct Node *n)
{
    while (n != NULL)
    {
        // Insert data
        printf("%c", n->data);
        n = n->next;
    }
    printf("\n");
}

/**
 * Creates a copy of your list
 */
struct Node *LLcopy(struct Node *head)
{
    struct Node *new = LLinit(head->data);
    struct Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
        LLadd(new, curr->data);
    }
    return new;
}

/**Gives int length of the length of your list*/
int LLlen(struct Node *head)
{
    int count = 0;
    struct Node *curr = head;
    while (curr->next != NULL)
    {
        curr = curr->next;
        count++;
    }
    count++;
    return count;
}

/**
 * Cuts a list down to just within the params, both sides are inclusive
 * head must be &head
 */
void LLslice(struct Node **head, int first, int last)
{
    int i = 0;
    while (i < first)
    {
        LLremove(head, 0);
        i++;
    }
    last -= (first);
    int len = LLlen(*head);
    for (int j = 0; j < len - last - 1; j++)
    {
        LLpop(*head);
    }
}

/**
 * Returns a copied and sliced sublist
 */
struct Node *LLsublist(struct Node *head, int first, int last)
{
    struct Node *copy = LLcopy(head);
    LLslice(&copy, first, last);
    return copy;
}

/**
 * returns the amount of data being used by malloc in Bytes
 */
int LLsize(struct Node *head)
{
    return sizeof(struct Node) * LLlen(head);
}

/**
 * Flips the list backwards
 * Must be given &head
 */
void LLflip(struct Node **head)
{
    struct Node *old = *head;
    struct Node *hold = (*head)->next;
    (*head)->next = NULL;
    struct Node *curr = hold;
    while (curr->next != NULL)
    {
        hold = curr->next;
        curr->next = old;
        old = curr;
        curr = hold;
    }
    curr->next = old;
    *head = curr;
}

/**
 * Returns the index of the first node with the data you want.
 * Returns -1 if none found.
 *
 * Change the return type of this
 * to whatever it is you want to search by.
 *
 */
int LLindexOf(struct Node *head, int wanted)
{
    struct Node *curr = head;
    int index = 0;
    while (curr != NULL)
    {
        if (curr->data == wanted)
        {
            return index;
        }
        else
        {
            curr = curr->next;
            index++;
        }
    }
    return -1;
}

/**
 * Creates a string from the data in the list
 * Don't forget to free this later!
 */
char *LLtoString(struct Node *head)
{
    char *word = malloc(LLlen(head) + 1);
    struct Node *curr = head;
    int i = 0;
    while (curr != NULL)
    {
        // printf("%c", curr->data);
        word[i] = curr->data;
        curr = curr->next;
        i++;
    }
    word[i + 1] = '\0';
    return word;
}


/**
 * Removes the entire list
*/
void LLclear(struct Node *head) {
    struct Node *temp;
    while (head -> next != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/**
 * Put a whole list into the middle of another list
 * right after index n
*/
void LLinsertList(struct Node* head, int n, struct Node* in)
{
    struct Node* curr = LLget(head, n);
    struct Node* connect = curr -> next;
    curr ->next = in;
    while (curr->next != NULL){
        curr = curr -> next;
    }
    curr -> next = connect;
}

/**
 * Turns a string into a linked list
*/
struct Node* LLstrToList(char* str){
    struct Node* list = (struct Node *)malloc(sizeof(struct Node));
    list = LLinit(str[0]);
    for(int i = 1; i < strlen(str); i++){
        LLadd(list, str[i]);
    }
    return list;
}



int main(){
    struct Node* list = LLinit(0);
    for(int i = 1; i < 20; i++){
        LLadd(list, i);
    }
    //LLprint(list);

    for(int i = 0; i < 20; i++){
        for (int j = i + 1; j < 20; j++){
            struct Node* cut = LLsublist(list, i, j - 1);
            LLprint(cut);
            LLclear(cut);
        }
    }
}