#include <stdio.h>
#include <stdlib.h>

struct node *f = NULL;
struct node *r = NULL;

struct node
{
    int data;
    struct node *link;
};

void enqueue(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        printf("Queue overflow\n");
    }
    else
    {
        n->data = data;
        n->link = NULL;
        if (f == NULL)
        {
            f = n;
            r = n;
        }
        else
        {
            r->link = n;
            r = n;
        }
    }
}

int dequeue()
{
    int value;
    struct node *ptr;
    if (f == NULL)
    {
        printf("Queue underflow\n");
    }
    else
    {
        ptr = f;
        f = f->link;
        value = ptr->data;
        free(ptr);
    }
    return value;
}

void Travarse_node(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->link;
    }
}

int main()
{
    enqueue(54);
    enqueue(5);
    enqueue(4);
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    // Travarse_node(f);
    return 0;
}