#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertNodeEnd(struct Node **head, int data);
void printLList(struct Node *node);
void freeLList(struct Node *head);
struct Node *generateNode(int data);


int main(int argc, char const *argv[])
{
    char req[10] = {};
    struct Node *head = NULL; // içi boş node bir pointer
    struct Node *select = NULL; // içi boş node bir pointer

    puts("Single Link List Created");
    //printLList(head);

    for (int i = 10; i < 30; i += 3)
    {
        insertNodeEnd(&head, i);
    }
    printLList(head);
        
    while (1)
    {
        puts("main menu");
        scanf("%s",req);
        if (strcmp(req,"traverse")==0)
        {
            select = head;
            struct Node *previous = NULL;

            while (1)
            {
                printf("selected : %d\n",select->data);
                scanf("%s",req);
                   
                if (strcmp(req,"next")==0)
                {
                    previous = select;
                    select = select->next;
                }

                if (strcmp(req,"delete")==0)
                {
                    previous->next = select->next;
                    free(select);
                    break;
                }
                
                
                if (strcmp(req,"return")==0)
                {
                    break;
                }

                if (strcmp(req,"exit")==0)
                {
                    break;
                }
            
            }

            // exit app
            if (strcmp(req,"exit")==0)
            {
                break;
            }
        }
        
    }
    freeLList(head);
    return 0;
}

// traverse:
// insert: end head ??selected location
// delete: end head ??selected location or element.
// search:
// sort:


void insertNodeEnd(struct Node **head, int data)
{
    if (*head == NULL)
    {
        *head = generateNode(data);
        return;
    }

    insertNodeEnd(&((*head)->next), data);//Is it wrong to be recursive?
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
    printf("SLL : ");
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

// if (strcmp(req,"r-fill")==0)
// {
//     for (int i = 10; i < 30; i += 3)
//     {
//         insertNodeEnd(&head, i);
//     }
// }