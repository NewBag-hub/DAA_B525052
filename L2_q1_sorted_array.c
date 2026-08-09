#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int size=10;
int top=0;

struct element{
    int key;
    int value;
};


struct element *Search(struct element *D,int k){
    for (int i=0;i<=top;i++){
        if(k==(D+i)->key)return D+i;
    }
    printf("Element not found...");
    return NULL;
}

void Insert(struct element *D,struct element*x){
    if (top==size){
        printf("Dictionary overflow!!");
        return;
    }
    struct element temp;

    int i=0;
    for (i;i<top;i++) if ((D+i)->key>x->key) break;

    for (int j=top;j>i;j--){
        (D+j)->key = (D+j-1)->key;
        (D+j)->value = (D+j-1)->value;
    }

    (D+i)->key=x->key;
    (D+i)->value=x->value;
    top++;
    printf("Element inserted.\n");
}

void Delete(struct element *D,struct element *x){
    int i=0;
    for (i=0;i<top;i++){
        if ((D+i)->key==x->key) break;
    }
    for(++i;i<top;i++){
        (D+i-1)->key=(D+i)->key;
        (D+i-1)->value=(D+i)->value;
    }
    printf("Element Deleted.");
}

struct element *Min(struct element *D){
    return (D+0);
}

struct element *Max(struct element *D){
    return (D+top-1);
}

struct element *Predecessor(struct element *D,struct element *x){
    for(int i=0;i<top;i++){
        if((D+i)->key==x->key) return (D+i-1);
    }
    return NULL;
}

struct element *Successor(struct element *D,struct element *x){
    for(int i=0;i<top;i++){
        if((D+i)->key==x->key) return (D+i+1);
    }
    return NULL;
}


int main(){
    struct element *D,*a;
    int option,k;

    D=malloc(size*sizeof(struct element));

    while(1){
        printf("Enter choice:\n0. Exit\n1. Insert\n2. Search\n3. Delete\n4. Min\n5. Max\n6. Predecessor\n7. Successor\n8. Display\n");
        scanf("%d",&option);
        switch(option){
            case 0:
                free(D);
                return 0;
                break;
            case 1:
                printf("Enter key then value :\n");
                scanf("%d %d",&(a->key),&(a->value));
                Insert(D,a);
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d",&k);
                a=Search(D,k);
                if (a!=NULL) printf("Key: %d\nValue: %d\n",a->key,a->value);
                break;
            case 3:
                printf("Enter element key to delete: ");
                scanf("%d",&k);
                Delete(D,Search(D,k));
                break;
            case 4:
                a=Min(D);
                printf("Element with MINIMUM key value:");
                printf("Key: %d\nValue: %d\n",a->key,a->value);
                break;
            case 5:
                a=Max(D);
                printf("Element with MAXIMUM key value:");
                printf("Key: %d\nValue: %d\n",a->key,a->value);
                break;
            case 6:
                printf("Enter the key of the element to find its Predecessor: ");
                scanf("%d",k);
                a=Predecessor(D,Search(D,k));
                printf("PREDECESSOR:");
                printf("Key: %d\nValue: %d\n",a->key,a->value);
                break;
            case 7:
                printf("Enter the key of the element to find its Successor: ");
                scanf("%d",k);
                a=Successor(D,Search(D,k));
                printf("SUCCESSOR:");
                printf("Key: %d\nValue: %d\n",a->key,a->value);
                break;
            case 8:
                printf("CURRENT DICTIONARY:\n{");
                for (int i=0;i<=top;i++){
                    printf("%d\t: %d;\n",(D+i)->key,(D+i)->value);
                }
                printf("}\n");
                break;
            default: printf("Invalid Input");
        }
    }
    free(D);
    return 0;
}