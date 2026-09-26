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
    yeni->data=40;
    yeni->next=NULL;

    struct node *iter = root;
    while (iter->next != NULL) {
        iter = iter->next;
    }
    iter->next=yeni;
    iter = root;
    while (iter != NULL) {
        printf("%d -> ", iter->data);
        iter = iter->next;
    }
    printf("NULL\n");
    iter = root;
    while (iter != NULL) {
        struct node *temp = iter;
        iter = iter->next;
        free(temp);
    }
    return 0;
}
