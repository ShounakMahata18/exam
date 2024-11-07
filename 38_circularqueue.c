#include <stdio.h>
#include <stdlib.h>
#define Max 5

int arr[Max];
int f = 0, r = 0;

void enqueue(int data)
{
    if ((r + 1) % Max == f)
        printf("Queue overflow\n");
    else
    {
        r = (r + 1) % Max;
        arr[r] = data;
    }
}

int dequeue()
{
    if (r == f)
        printf("Stack underflow\n");
    int value;
    f = (f + 1) % Max;
    value = arr[f];
    return value;
}

int main()
{
    enqueue(12);
    enqueue(54);
    enqueue(42);
    enqueue(92);
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    enqueue(74);
    enqueue(85);
    enqueue(57);
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
}