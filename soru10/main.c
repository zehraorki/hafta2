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
    int sayi;
    printf("Lutfen silmek istediginiz sayiyi giriniz: ");
    scanf("%d",&sayi);
    if (root != NULL && root->data == sayi) {
        struct node *temp = root;
        root = root->next;
        free(temp);
    } else {
        struct node *previous = NULL;
        struct node *current = root;

        while (current != NULL && current->data != sayi) {
            previous = current;
            current = current->next;
        }
        if (current != NULL) {
            previous->next = current->next;
            free(current);
        } else {
            printf("Eleman listede bulunamadi!\n");
        }
    }
    struct node *iter = root;
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