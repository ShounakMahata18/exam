#include <stdio.h>
#include <stdlib.h>
#define Max 100

int arr[Max];
int f = -1;
int r = -1;

void enqueue(int data)
{
    if (r == Max - 1)
        printf("Queue overflow");
    r++;
    arr[r] = data;
}

int dequeue()
{
    if (r == f)
        printf("Queue underflow");
    int data;
    f++;
    data = arr[f];
    return data;
}

int main()
{
    enqueue(13);
    enqueue(32);
    enqueue(23);
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());

    if (r == Max - 1)
        printf("Queue overflow.");
    if (r == f)
        printf("Queue underflow");
    return 0;
}