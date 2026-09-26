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
    int sayi,sonuc=0;
    printf("Lutfen aramak istediginiz sayiyi giriniz: ");
    scanf("%d",&sayi);
    struct node *iter=root;
    while (iter!=NULL) {
        if (iter->data==sayi) {
            sonuc=1;
            break;
        }
        iter=iter->next;
    }
    if (sonuc==1) {
        printf("Aradiginiz sayi bulundu");
    }else {
        printf("Aradiginiz sayi bulunamadi!!");
    }
    iter = root;
    while (iter != NULL) {
        struct node *temp = iter;
        iter = iter->next;
        free(temp);
    }
    return 0;
}