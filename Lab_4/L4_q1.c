#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pair{
    int n;
    char str[7];
};

void input_array(struct pair *arr,int size){
    printf("Enter the elements of the array: \n");
    for (int i=0;i<size;i++){
        scanf("%d %s",&((arr+i)->n),(arr+i)->str);
    }
}

void print_array(struct pair *arr,int size){
    printf("Elements of the Array:\n");
    for (int i=0;i<size;i++){
        printf("%d\t%s\t",(arr+i)->n,(arr+i)->str);
    }
    printf("\n");
}

void swap(struct pair *a, struct pair *b){
    struct pair temp = *a;
    *a = *b;
    *b = temp;
}

void sort_color(struct pair *arr, int size){
    int red_top = 0;
    int blue_top = 0;
    int yellow_top = size - 1;

    while(blue_top <= yellow_top){
        if(strcmp(arr[blue_top].str, "red") == 0){
            swap(&arr[red_top], &arr[blue_top]);
            red_top++;
            blue_top++;
        } else if(strcmp(arr[blue_top].str, "blue") == 0){
            blue_top++;
        } else if(strcmp(arr[blue_top].str, "yellow") == 0){
            swap(&arr[blue_top], &arr[yellow_top]);
            yellow_top--;
        }
    }
}

int main(){
    int n;
    printf("Enter the number of pairs in the array: ");
    scanf("%d",&n);
    struct pair *arr=malloc(n*sizeof(struct pair));
    input_array(arr,n);
    sort_color(arr,n);
    print_array(arr,n);
    free(arr);
    return 0;
}
