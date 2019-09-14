#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(int *list,int x,int len){
    int i=0,j=len-1,k;
    while(i<=j){
        k=(i+j)/2;
        if(list[k]<x){
            i=k+1;
        }else if(list[k]>x){
            j=k-1;
        }else{
            return k;
        }
    }
    return -1;
}

int main(){
    int list[]={1,3,4,5,6,8,9};
    printf("%d\n",search(list,2,7));
    return 0;
}
