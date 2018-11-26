#include <stdio.h>
#include <stdlib.h>

int r;
int s;
int n;

struct feild {
        int coordinate;
        int count;
    };

void mergesort(struct feild a[],int i,int j);
void merge(struct feild a[],int min1,int max1,int min2,int max2);

void mergesort(struct feild a[],int i,int j)
{
    int mid;
    if(i<j)
    {
        mid=(i+j)/2;
        mergesort(a,i,mid);        
        mergesort(a,mid+1,j);    
        merge(a,i,mid,mid+1,j);    
    }
}
 
void merge(struct feild a[],int min1,int max1,int min2,int max2)
{
    int i,j,k;
    
    struct feild temp[n];

    i=min1;    
    j=min2;    
    k=0;
    
    while(i<=max1 && j<=max2)  
    {
        if(a[i].coordinate<a[j].coordinate) {
            temp[k].coordinate=a[i].coordinate;
            temp[k++].count=a[i++].count;
        }
        else {
            temp[k].coordinate=a[j].coordinate;
            temp[k++].count=a[j++].count;
        }
    }
    
    while(i<=max1) {    
        temp[k].coordinate=a[i].coordinate;
        temp[k++].count=a[i++].count;
    }
        
    while(j<=max2) {
        temp[k].coordinate=a[j].coordinate;
        temp[k++].count=a[j++].count;
    }
        
    for(i=min1,j=0;i<=max2;i++,j++) {
        a[i].coordinate=temp[j].coordinate;
        a[i].count=temp[j].count;
    }
}
int getBest(struct feild arr[], int size, long long int total){
    total = total/2;
    for(int x = 0; x<size; x++){
        total = total - arr[x].count;
        if(total < 0){
            return arr[x].coordinate;
        }
    }
}
    
int main() {
    
    long long int totalPeople = 0;
    scanf("%d %d %d", &r, &s, &n);
    struct feild osaX[n];
    struct feild osaY[n];

    for(int z=0; z<n; z++){
        osaX[z].coordinate = 0;
        osaX[z].count = 0;
        osaY[z].coordinate = 0;
        osaY[z].count = 0;
    }
    
    int c = 0;

    for(int m = 0; m<n; m++){
        int x;
        int y ;
        int num;
        
        scanf("%d %d %d", &x, &y, &num);
        if(num>0){
            osaX[c].coordinate = x;
            osaY[c].coordinate = y;
            osaX[c].count = num;
            osaY[c].count = num;
            c++;
            totalPeople += num;
        }
        
        
    }
    
    mergesort(osaX, 0, n-1);
    mergesort(osaY, 0, n-1);
   
    int resX;
    resX = getBest(osaX, n, totalPeople);
    int resY;
    resY = getBest(osaY, n, totalPeople);
    
    printf("%d %d", resX, resY);
    
}


    


