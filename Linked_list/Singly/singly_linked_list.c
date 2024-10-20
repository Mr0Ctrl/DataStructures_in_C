#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void addNodeEnd(struct Node **head, int data);
void printLList(struct Node *node);
void freeLList(struct Node *head);
struct Node *generateNode(int data);


int main(int argc, char const *argv[])
{
    struct Node *head = NULL; // içi boş node bir pointer

    for (int i = 10; i < 30; i += 3)
    {
        addNodeEnd(&head, i);
    }

    printLList(head);
    freeLList(head);

    return 0;
}

void addNodeEnd(struct Node **head, int data)
{
    if (*head == NULL)
    {
        *head = generateNode(data);
        return;
    }

    addNodeEnd(&((*head)->next), data);//Is it wrong to be recursive?
    return;
}


/// basic functions
struct Node *generateNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printLList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
    return;
}

void freeLList(struct Node *head)
{
    if (head == NULL)
    {
        return;
    }
    freeLList(head->next);
    free(head);
}
