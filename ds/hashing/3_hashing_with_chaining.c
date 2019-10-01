#include <stdio.h>
#include <stdlib.h>

int Bucket; 
typedef struct node_t{
    int value; 
    struct node_t *next; 
} node; 

int hashFunc(int x) {
    return (x%Bucket);
}

node *create(int val) {
    node *nd = (node *)malloc(sizeof(node));
    nd->value = val; 
    nd->next = NULL; 
    return nd;
}

void insert(node **hash, int a) {
    int key = hashFunc(a);
    if (!hash[key]) {
        hash[key] = create(a);
    } else {
        node *tmp = hash[key];  
        while (tmp->next)
            tmp=tmp->next;
        tmp->next = create(a); 
    }
    return; 
}

void display(node **hash) {
    for(int i=0; i<Bucket;i++) {
        printf("[%d]: ", i); 
        node *tmp = hash[i];
        while(tmp) {
            printf("%d ", tmp->value);
            tmp = tmp->next;
        }
        printf("\n");
    }
    printf("\n");
}
void deletev(node **hash, int v) {
    int key = hashFunc(v);
    node *tmp = hash[key];
    if (tmp && tmp->value == v) {
        hash[key] = tmp->next; 
        free(tmp);
    } else {
        node *prev = tmp;
        node *next = tmp->next;
        while (next) {
            if (next->value==v) {
                prev->next = next->next;
                free(next);
                return;
            }
            prev = next; 
            next = next->next;
        }
        if (!next)
            printf("%d not found\n", v);
    }
}
int main( ) {
    int a[] = {15, 11, 27, 8, 12}; 
    int n = sizeof(a)/sizeof(a[0]); 

    Bucket = 7; 
    node **hash; 
    hash = (node **)malloc (sizeof(node *)*Bucket);
    for(int i=0; i<Bucket;i++) {
        hash[i] = NULL; //(node *) malloc(sizeof(node *));
        //hash[i]->value = -1;
        //hash[i]->next = NULL;
    }

    for(int i=0; i<n; i++)
        insert(hash, a[i]);

    display(hash); 
    deletev(hash, 12);
    printf("Delete 12\n");
    display(hash);

    deletev(hash, 15);
    printf("Delete 15\n");
    display(hash);   

    insert(hash, 12); 
    insert(hash, 15);
    printf("Inserted 12 and 15\n");
    display(hash);

    deletev(hash, 8);
    printf("delete 8\n");
    display(hash);
}