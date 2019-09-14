#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct record {
    int key;
    int others;
};

int bisearch(struct record r[],int n, int k)
{
    int low=0,mid,high=n-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(r[mid].key==k)
            return mid+1;
        else if(r[mid].key>k)
            high=mid-1;
        else low=mid+1;
    }
    return 0;
}

int main(){
    struct record list[7]={1,0,2,0,3,0,4,0,6,0,7,0,9,0};
    printf("%d\n",bisearch(list,7,3));
    return 0;
}
