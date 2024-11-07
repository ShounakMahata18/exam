#include<stdio.h>
#include<stdlib.h>

struct myArray
{
    int total_size;
    int used_size;
    int *ptr;
};

void createarray(struct myArray *a, int tsize, int usize){
    a->total_size=tsize;
    a->used_size=usize;
    int *ptr=(int*) malloc(tsize * sizeof(int));
}

void setvalue(struct myArray *a){
    int n;
    for (int i= 0; i < a->used_size; i++){
        printf("Enter Value of %d is:",i);
        scanf("%d",&n);
        (a->ptr)[i]=n;
    }   
}

void show(struct myArray *a){
    for (int i= 0; i < a->used_size; i++){
        printf("%d\n",(a->ptr)[i]);
    }
}

int main (){
    struct myArray marks;
    createarray(&marks,10,4);
    setvalue(&marks);
    show(&marks);
    return 0;
}