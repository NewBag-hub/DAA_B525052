#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct element {
    int key;
    int value;
    struct element *next;
};


struct element *Search(struct element *D, int k) {
    struct element *p = D;

    while (p != NULL) {
        if (p->key == k)
            return p;
        p = p->next;
    }
    printf("Element not found...\n");
    return NULL;
}

void Insert(struct element **D, struct element *x) {
    struct element *newNode;

    newNode = malloc(sizeof(struct element));
    newNode->key = x->key;
    newNode->value = x->value;

    newNode->next = *D;
    *D = newNode;

    printf("Element inserted.\n");
}

void Delete(struct element **D, struct element *x) {
    struct element *p = *D;
    struct element *prev = NULL;

    while (p != NULL && p->key != x->key) {
        prev = p;
        p = p->next;
    }

    if (p == NULL) {
        printf("Element not found.\n");
        return;
    }

    if (prev == NULL) {
        *D = p->next;
    } 
    else {
        prev->next = p->next;
    }
    free(p);

    printf("Element deleted.\n");
}

struct element *Min(struct element *D) {
    struct element *minNode = D;
    struct element *p = D->next;

    while (p != NULL) {
        if (p->key < minNode->key)
            minNode = p;

        p = p->next;
    }

    return minNode;
}

struct element *Max(struct element *D) {
    struct element *maxNode = D;
    struct element *p = D->next;

    while (p != NULL) {
        if (p->key > maxNode->key)
            maxNode = p;

        p = p->next;
    }

    return maxNode;
}

struct element *Predecessor(struct element *D, struct element *x) {
    struct element *pred = NULL;
    struct element *p = D;

    while (p != NULL) {
        if (p->key < x->key) {
            if (pred == NULL || p->key > pred->key)
                pred = p;
        }

        p = p->next;
    }
    return pred;
}

struct element *Successor(struct element *D, struct element *x) {
    struct element *succ = NULL;
    struct element *p = D;

    while (p != NULL) {
        if (p->key > x->key) {
            if (succ == NULL || p->key < succ->key)
                succ = p;
        }

        p = p->next;
    }

    return succ;
}

void Display(struct element *D) {
    struct element *p = D;

    printf("CURRENT DICTIONARY:\n{");

    while (p != NULL) {
        printf("%d : %d;\n", p->key, p->value);
        p = p->next;
    }

    printf("}\n");
}

void FreeList(struct element *D) {
    struct element *temp;

    while (D != NULL) {
        temp = D;
        D = D->next;
        free(temp);
    }
}

int main() {
    struct element *D = NULL, *a, x;
    int option, k;

    while (1) {

        printf("\nEnter choice:\n0. Exit\n1. Insert\n2. Search\n3. Delete\n4. Min\n5. Max\n6. Predecessor\n7. Successor\n8. Display\n");
        scanf("%d", &option);

        switch (option) {
            case 0:
                FreeList(D);
                return 0;

            case 1:
                printf("Enter key then value:\n");
                scanf("%d %d", &x.key, &x.value);

                Insert(&D, &x);
                break;

            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &k);

                a = Search(D, k);
                if (a != NULL) {
                    printf("Key: %d\n", a->key);
                    printf("Value: %d\n", a->value);
                }
                break;

            case 3:
                printf("Enter element key to delete: ");
                scanf("%d", &k);

                a = Search(D, k);
                if (a != NULL)
                    Delete(&D, a);
                break;

            case 4:
                a = Min(D);

                printf("Element with MINIMUM key value:\n");
                printf("Key: %d\nValue: %d\n",a->key, a->value);
                break;

            case 5:
                a = Max(D);
                printf("Element with MAXIMUM key value:\n");
                printf("Key: %d\nValue: %d\n", a->key, a->value);
                break;

            case 6:
                printf("Enter the key of the element to find its Predecessor: ");
                scanf("%d", &k);
                a = Search(D, k);
                if (a != NULL) {
                    struct element *pred = Predecessor(D, a);

                    if (pred != NULL) {
                        printf("PREDECESSOR:\n");
                        printf("Key: %d\nValue: %d\n",pred->key, pred->value);
                    } 
                    else printf("No predecessor exists.\n");
                }
                break;

            case 7:
                printf("Enter the key of the element to find its Successor: ");
                scanf("%d", &k);

                a = Search(D, k);
                if (a != NULL) {
                    struct element *succ = Successor(D, a);
                    if (succ != NULL) {
                        printf("SUCCESSOR:\n");
                        printf("Key: %d\nValue: %d\n",succ->key, succ->value);
                    } else printf("No successor exists.\n");
                }
                break;

            case 8:
                Display(D);
                break;

            default: printf("Invalid option.\n");
        }
    }

    return 0;
}
