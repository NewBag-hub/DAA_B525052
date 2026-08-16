#include <stdio.h>
#include <stdlib.h>

int Binary_Search(int *arr,int p,int q,int x){
    if(p>q) return -1;
    else if (p>=q){
        if (x==*(arr+p)) return p;
        else return -1;
    }

    int mid=p+(q-p)/2;
    if (x > *(arr+mid)) return Binary_Search(arr,mid+1,q,x);
    else return Binary_Search(arr,p,mid,x);
}

int Ternary_Search(int *arr,int p,int q,int x){
    if(p>q) return -1;
    else if (p==q){
        if(x==*(arr+p)) return p;
        else return -1;
    }

    int m1=p+(q-p)/3, m2=q-(q-p)/3;
    if (x<*(arr+m1)) return Ternary_Search(arr,p,m1-1,x);
    else if (x<*(arr+m2)) return Ternary_Search(arr,m1,m2-1,x);
    else return Ternary_Search(arr,m2,q,x);
}

void Input_Array(int *arr,int size){
    printf("Enter the elements of the array:\n");
    for (int i=0;i<size;i++)scanf("%d",arr+i);
}

int main(){
    int n,*arr,x,index;
    printf("Enter the total number of elements: ");
    scanf("%d",&n);
    arr=malloc(n*sizeof(int));

    Input_Array(arr,n);
    for (int i=0;i<n;i++) printf("%d\t",*(arr+i));
    printf("\n");
    printf("Enter the element you want to search: ");
    scanf("%d",&x);

    //BINARY SEARCH
    index=Binary_Search(arr,0,n-1,x);

    if(index==-1)printf("Element not found!!\n");
    else printf("Element found using Binary Search at %d index\n",index);

    //TERNARY SEARCH
    index=Ternary_Search(arr,0,n-1,x);

    if(index==-1)printf("Element not found!!\n");
    else printf("Element found using Ternary Search at %d index\n",index);

    free(arr);
    return 0;
}