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
    root->next->next=(struct node*)malloc(sizeof(struct node));
    root->next->next->data=30;
    root->next->next->next=(struct node*)malloc(sizeof(struct node));
    root->next->next->next->data=40;
    root->next->next->next->next=NULL;

    int i=0;
    struct node *iter=root;
    while (iter!=NULL) {
        i++;
        iter=iter->next;
    }
    printf("Liste %d adet node içerir.",i);

    iter = root;
    while (iter != NULL) {
        struct node *temp = iter;
        iter = iter->next;
        free(temp);
    }    return 0;
}


