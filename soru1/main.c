#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

int main(void) {
    struct node *root =(struct node* )malloc(sizeof(struct node));
    root ->data=10;
    root->next=NULL;

    printf("Veri : %d ",root->data);

    free(root);

    return 0;
}

