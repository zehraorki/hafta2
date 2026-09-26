#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

int main(void) {
    struct node *root = (struct node *)malloc(sizeof(struct node));
    root->data=10;
    root->next=(struct node*)malloc(sizeof(struct node));
    root->next->data=20;
    root->next->next=NULL;

    printf("%d -> %d -> NULL",root->data,root->next->data);

    free(root->next);
    free(root);

    return 0;
}
