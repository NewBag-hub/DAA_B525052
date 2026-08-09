#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct element {
    int key;
    int value;
    struct element *next;
    struct element *prev;
};

struct element *Search(struct element *D, int k) {
    struct element *p = D;

    while (p != NULL) {
        if (p->key == k)
            return p;

        if (p->key > k)
            break;
        p = p->next;
    }
    printf("Element not found...\n");
    return NULL;
}

void Insert(struct element **D, struct element *x) {
    struct element *newNode;
    struct element *p;

    newNode = malloc(sizeof(struct element));
    newNode->key = x->key;
    newNode->value = x->value;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*D == NULL) {
        *D = newNode;
        printf("Element inserted.\n");
        return;
    }

    if ((*D)->key > x->key) {
        newNode->next = *D;
        (*D)->prev = newNode;
        *D = newNode;

        printf("Element inserted.\n");
        return;
    }
    p = *D;

    while (p->next != NULL && p->next->key < x->key) {
        p = p->next;
    }
    newNode->next = p->next;
    newNode->prev = p;

    if (p->next != NULL)
        p->next->prev = newNode;
    p->next = newNode;

    printf("Element inserted.\n");
}
void Delete(struct element **D, struct element *x) {
    if (x->prev == NULL) {
        *D = x->next;
        if (*D != NULL)
            (*D)->prev = NULL;
    }

    else {
        x->prev->next = x->next;
        if (x->next != NULL)
            x->next->prev = x->prev;
    }
    free(x);
    printf("Element Deleted.\n");
}

struct element *Min(struct element *D) {
    return D;
}
struct element *Max(struct element *D) {
    struct element *p = D;

    while (p->next != NULL)
        p = p->next;
    return p;
}

struct element *Predecessor(struct element *D, struct element *x) {
    return x->prev;
}
struct element *Successor(struct element *D, struct element *x) {
    return x->next;
}

void Display(struct element *D) {
    struct element *p = D;

    printf("CURRENT DICTIONARY:\n{");
    while (p != NULL) {
        printf("%d\t: %d;\n", p->key, p->value);
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
    struct element *D = NULL;
    struct element *a;
    struct element x;
    int option, k;

    while (1) {
        printf("Enter choice:\n0. Exit\n1. Insert\n2. Search\n3. Delete\n4. Min\n5. Max\n6. Predecessor\n7. Successor\n8. Display\n");
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
                if (a != NULL) {
                    printf("Element with MINIMUM key value:\n");
                    printf("Key: %d\n", a->key);
                    printf("Value: %d\n", a->value);
                }
                else printf("Dictionary is empty.\n");
                break;

            case 5:
                a = Max(D);
                if (a != NULL) {
                    printf("Element with MAXIMUM key value:\n");
                    printf("Key: %d\n", a->key);
                    printf("Value: %d\n", a->value);
                }
                else printf("Dictionary is empty.\n");
                break;

            case 6:
                printf("Enter the key of the element to find its Predecessor: ");
                scanf("%d", &k);
                a = Search(D, k);

                if (a != NULL) {
                    struct element *pred = Predecessor(D, a);
                    if (pred != NULL) {
                        printf("PREDECESSOR:\n");
                        printf("Key: %d\n", pred->key);
                        printf("Value: %d\n", pred->value);
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
                        printf("Key: %d\n", succ->key);
                        printf("Value: %d\n", succ->value);
                    }
                    else printf("No successor exists.\n");
                }
                break;

            case 8:
                Display(D);
                break;

            default: printf("Invalid Input\n");
        }
    }
    return 0;
}
