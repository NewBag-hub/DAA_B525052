#include <stdio.h>
#include <limits.h>
#include <stdlib.h>


void input_array(int *arr,int size){
    printf("Enter the elements of the array:\n");
    for(int i=0;i<size;i++) scanf("%d",arr+i);
}
void print_array(int *arr,int size){
    printf("Array :");
    for (int i=0;i<size;i++) printf("%d\t",*(arr+i));
    printf("\n");
}

void Merge_3_way(int *arr,int p,int m1,int m2,int q){
    int n1=m1-p+1, n2=m2-m1, n3=q-m2, l1[n1+1], l2[n2+1], l3[n3+1], i,j,k,l;

    for (i=0;i<n1;i++) l1[i]=*(arr+p+i);
    l1[n1]=INT_MAX;
    for (i=0;i<n2;i++) l2[i]=*(arr+m1+1+i);
    l2[n2]=INT_MAX;
    for (i=0;i<n3;i++) l3[i]=*(arr+m2+1+i);
    l3[n3]=INT_MAX;

    i=0;j=0;k=0;
    for (l=p;l<q+1;l++){
        if ((l1[i]<l2[j] && l1[i]<l3[k])){
            *(arr+l)=l1[i];
            i++;
        }
        else if(l2[j]<l1[i] && l2[j]<l3[k]){
            *(arr+l)=l2[j];
            j++;
        }
        else{
            *(arr+l)=l3[k];
            k++;
        }
    }
}

void Merge_Sort_3_way(int *arr,int p,int q){
    if (q-p>0){
        int m1=p+(q-p)/3, m2=q-(q-p)/3;
        Merge_Sort_3_way(arr,p,m1);
        Merge_Sort_3_way(arr,m1+1,m2);
        Merge_Sort_3_way(arr,m2+1,q);
        Merge_3_way(arr,p,m1,m2,q);
    }
}


int main(){
    int *arr,n;
    printf("Enter total no of element: ");
    scanf("%d",&n);
    arr=malloc(n*sizeof(int));

    input_array(arr,n);
    Merge_Sort_3_way(arr,0,n-1);
    print_array(arr,n);
    free(arr);
    return 0;
}