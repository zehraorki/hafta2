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
    root->next->next->next=NULL;

    struct node *yeni = (struct node *)malloc(sizeof(struct node));
    yeni->data=5;
    yeni->next=root;
    root=yeni;

    while (yeni!= NULL) {
        printf("%d -> ",yeni->data);
        yeni = yeni -> next;
    }
    printf("NULL");

    yeni = root;
    while (yeni != NULL) {
        struct node *temp = yeni;
        yeni = yeni->next;
        free(temp);
    }
    return 0;
}

