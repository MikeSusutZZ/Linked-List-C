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
 * Puts a new element at a chosen index
 * (must be passed &head)
 */
void LLinsert(struct Node **head, int index, int data)
{
    struct Node *curr = *head;
    struct Node *new = (struct Node *)malloc(sizeof(struct Node));
    if (index != 0){
    for (int i = 0; i < index - 1; i++)
    {
        curr = curr->next;
    }
    
    new->next = curr->next;
    curr->next = new;}
    else {
        new -> next = curr;
        *head = new;
    }
    // Insert data
    new->data = data;
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
 * Takes the node at index n out of the list
 * and then returns it
 */
struct Node *LLpull(struct Node *head, int n)
{
    struct Node *curr = head;
    for (int i = 0; i < n - 1; i++)
    {
        curr = curr->next;
    }
    struct Node *save = curr->next;
    curr->next = curr->next->next;
    return save;
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
void LLclear(struct Node *head)
{
    struct Node *temp;
    while (head->next != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

/**
 * Put a whole list into the middle of another list
 * right after index n
 */
void LLinsertList(struct Node *head, int n, struct Node *in)
{
    struct Node *curr = LLget(head, n);
    struct Node *connect = curr->next;
    curr->next = in;
    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = connect;
}

/**
 * Swaps the position between 2 nodes at the given indexes
 * (must be passed &head)
 */
void LLswap(struct Node **head, int n, int m)
{
    if (m == 0)
    {
        int temp = n;
        n = m;
        m = temp;
    }
    if (n == 0)
    {
        struct Node *secBefore = LLget(*head, m - 1);
        struct Node *sec = secBefore->next;
        struct Node *first = LLget(*head, n);
        secBefore->next = first;
        struct Node *temp = first->next;
        first->next = sec->next;
        sec->next = temp;
        *head = sec;
    }
    else if (n != 0 && m != 0)
    {
        struct Node *firstBefore = LLget(*head, n - 1);
        struct Node *secBefore = LLget(*head, m - 1);
        struct Node *first = firstBefore->next;
        struct Node *sec = secBefore->next;
        firstBefore->next = sec;
        secBefore->next = first;
        struct Node *temp = first->next;
        first->next = sec->next;
        sec->next = temp;
    }
}

/**
 * Moves the position of a node at indexWanted to the indexMovedTo
 * (must pass &head)
 */
void LLmove(struct Node **head, int indexWanted, int indexMovedTo)
{
    if (indexWanted != 0 && indexMovedTo != 0)
    {
        struct Node *before = LLget(*head, indexWanted - 1);
        struct Node *target = before->next;
        before->next = before->next->next;
        struct Node *spot = LLget(*head, indexMovedTo - 1);
        struct Node *save = spot->next;
        spot->next = target;
        target->next = save;
    }
    else if (indexMovedTo == 0)
    {
        struct Node *before = LLget(*head, indexWanted - 1);
        struct Node *target = before->next;
        before->next = before->next->next;
        struct Node *save = *head;
        *head = target;
        target->next = save;
    }
    else if (indexWanted == 0)
    {
        struct Node *target = *head;
        *head = (*head)->next;
        struct Node *spot = LLget(*head, indexMovedTo - 1);
        struct Node *save = spot->next;
        spot->next = target;
        target->next = save;
    }
}

/**
 * Sorts a linked list by the value in data
 * from lowest to highest
 * (must pass &head)
 */
void LLsort(struct Node **head)
{
    int len = LLlen(*head);
    for (int i = 1; i < len; i++)
    {
        struct Node *curr = LLget(*head, i);

        for (int j = 0; j < i; j++)
        {
            struct Node *check = LLget(*head, j);
            // printf("comparing %d against %d, at indexes %d, %d\n", curr->data, check->data, i, j);
            if (check->data > curr->data)
            {
                LLmove(head, i, j);
                break;
            }
        }
    }
}

/**
 * Sorts a linked list by the value in chars
 * (must pass &head)
 */
// void LLsortChar(struct Node **head)
// {
//     int len = LLlen(*head);
//     for (int i = 1; i < len; i++)
//     {
//         struct Node *curr = LLget(*head, i);
//         int go = 1;

//         for (int j = 0; j < i; j++)
//         {
//             if (go)
//             {
//                 struct Node *check = LLget(*head, j);
//                 for (int letter = 2; letter < 9; letter++)
//                 {
//                     //char cu = curr->data[letter];
//                     //char ch = check->data[letter];
//                     if (ch > cu)
//                     {
//                         LLmove(head, i, j);
//                         go = 0;
//                         break;
//                     }
//                 }
//             }
//         }
//     }
// }

// struct Node* LLmergeSort(struct Node* listA, struct Node* listB){
//     struct Node* currA = listA;
//     struct Node* currB = listB;
//     struct Node* ret;
//     if (currA->data <= currB->data){
//         ret = LLinit(currA->data);
//         currA = currA->next;
//     } else {
//         ret = LLinit(currB->data);
//         currB = currB->next;
//     }
//     while(currA != NULL && currB != NULL) {
//         if (currA->data <= currB->data){
//             ret = LLadd(ret, currA->data);
//         currA = currA->next;
//         }
//     }
// }

/**
 * Turns a string into a linked list
 */
struct Node *LLstrToList(char *str)
{
    struct Node *list = (struct Node *)malloc(sizeof(struct Node));
    list = LLinit(str[0]);
    for (int i = 1; i < strlen(str); i++)
    {
        LLadd(list, str[i]);
    }
    return list;
}

int LLtotal(struct Node* head){
    int total = 0;
    struct Node* curr = head;
    while(curr != NULL){
        total += curr -> data;
        curr = curr -> next;
    }
    return total;
}


/**
 * Takes 2 linked lists and puts them together sorted
*/
struct Node* LLmerge(struct Node* left, struct Node* right) {
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }
    struct Node* result = NULL;
    if (left->data <= right->data) {
        result = left;
        result->next = LLmerge(left->next, right);
    } else {
        result = right;
        result->next = LLmerge(left, right->next);
    }
    return result;
}

/**
 * Separates a linked list into 2 new ones
 * pass in head, and 2 other points to hold the splits
*/
void LLsplit(struct Node* head, struct Node** left, struct Node** right) {
    struct Node* slow = head;
    struct Node* fast = head->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *left = head;
    *right = slow->next;
    slow->next = NULL;
}

/**
 * Merge sort
 * (must be passed &head)
*/
void LLmerge_sort(struct Node** head) {
    if (*head == NULL || (*head)->next == NULL) {
        return;
    }
    struct Node* left;
    struct Node* right;
    LLsplit(*head, &left, &right);
    LLmerge_sort(&left);
    LLmerge_sort(&right);
    *head = LLmerge(left, right);
}





int main(){
    struct Node* list = LLinit(1);
    LLadd(list, 4);
    LLadd(list, 45);
    LLadd(list, 30);
    LLadd(list, 25);
    LLadd(list, 1);
    LLadd(list, 3);
    LLadd(list, 2);
    LLprint(list);
    LLmerge_sort(&list);
    LLprint(list);
}
