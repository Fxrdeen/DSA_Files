
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char data;
    struct Node *next;
}NODE;

struct Node *createNode(char data)
{
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    temp->next = NULL;
    temp->data = data;
    return temp;
}

void insertAtEnd(struct Node **head, char data)
{
    NODE* temp = createNode( data);
    NODE* p = *head;
    if (*head==NULL) *head = temp;
    else{
        while(p->next!=NULL)
            p = p->next;
        p->next = temp;
    }
}

void removeVowels(struct Node **head)
{
   if (*head == NULL) return NULL;
    NODE* p = *head;
    while(p!=NULL){
        if (p->data == 'a' || p->data == 'e' || p->data=='i' || p->data == 'o' || p->data == 'u'){
            p->next = p->next->next;
        }
    }
}

void printReverse(struct Node *head)
{
    if (head == NULL)
        return;
    struct Node *current = head->prev;
    do
    {
        printf("%c", current->data);
        current = current->prev;
    } while (current != head->prev);
}

// Driver code
int main()
{
    int N;
    scanf("%d", &N);
    struct Node *head = NULL;
    for (int i = 0; i < N; i++)
    {
        char data;
        scanf(" %c", &data);
        insertAtEnd(&head, data);
    }
    removeVowels(&head);
    printReverse(head);
    return 0;
}
