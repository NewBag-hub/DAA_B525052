#include <stdio.h>
#include <stdlib.h>

void swap(float *a,float *b){
    float t=*a;
    *a=*b;
    *b=t;
}

int partition(float *arr,int p,int q){
    float x=*(arr+q);
    int i=p-1;
    for (int j=p;j<q;j++){
        if(*(arr+j) < x){
            i++;
            swap((arr+j),(arr+i));
        }
    }
    swap((arr+i+1),(arr+q));
    return i+1;
}

int quick_select(float *arr,int p,int q,int n){
    if (p<q){
        int r=partition(arr,p,q);
        if(r==n) return n;
        else if(r<n) return quick_select(arr,r+1,q,n);
        else return quick_select(arr,p,r-1,n);
    }
    return p;
}

float find_median(float *arr,int p,int q){
    int n=(q)/2;

    if ((q-p+1)%2==1){
        return *(arr+ quick_select(arr,p,q,n));
    } else{
        float a,b;
        a=*(arr+quick_select(arr,p,q,n));
        b=*(arr+quick_select(arr,p,q,n+1));
        return (a+b)/2;
    }
}

void input_array(float *arr,int size){
    printf("Enter the elements of the list:\n");
    for (int i=0;i<size;i++) scanf("%f",arr+i);
}

int main(){
    int n;
    printf("Enter the number of elements in the list: ");
    scanf("%d",&n);

    float *arr=malloc(n*sizeof(float)), median;
    input_array(arr,n);

    median=find_median(arr,0,n-1);
    printf("The median of the given numbers is %.1f\n",median);

    free(arr);
    return 0;
}
