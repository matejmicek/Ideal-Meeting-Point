#include <stdio.h>
#include <stdlib.h>

int r;
int s;
int n;

struct feild {
        int xxx;
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
        mergesort(a,i,mid);        //left recursion
        mergesort(a,mid+1,j);    //right recursion
        merge(a,i,mid,mid+1,j);    //merging of two sorted sub-arrays
    }
}
 
void merge(struct feild a[],int min1,int max1,int min2,int max2)
{
    int i,j,k;
    
    struct feild temp[n];

    i=min1;    //beginning of the first list
    j=min2;    //beginning of the second list
    k=0;
    
    while(i<=max1 && j<=max2)    //while elements in both lists
    {
        if(a[i].xxx<a[j].xxx) {
            temp[k].xxx=a[i].xxx;
            temp[k++].count=a[i++].count;
        }
        else {
            temp[k].xxx=a[j].xxx;
            temp[k++].count=a[j++].count;
        }
    }
    
    while(i<=max1) {    //copy remaining elements of the first list
        temp[k].xxx=a[i].xxx;
        temp[k++].count=a[i++].count;
    }
        
    while(j<=max2) {   //copy remaining elements of the second list
        temp[k].xxx=a[j].xxx;
        temp[k++].count=a[j++].count;
    }
        
    //Transfer elements from temp[] back to a[]
    for(i=min1,j=0;i<=max2;i++,j++) {
        a[i].xxx=temp[j].xxx;
        a[i].count=temp[j].count;
    }
}
int getBest(struct feild arr[], int size, long long int total){
    total = total/2;
    for(int xx = 0; xx<size; xx++){
        total = total - arr[xx].count;
        if(total < 0){
            return arr[xx].xxx;
        }
    }
}
    
int main() {
    
    long long int totalPeople = 0;
    //FILE *myFile;
    //myFile = fopen("C://cisla.in", "r");
    scanf("%d %d %d", &r, &s, &n);
    struct feild osaX[n];
    struct feild osaY[n];
    //nuluju arrays
    for(int z=0; z<n; z++){
        osaX[z].xxx = 0;
        osaX[z].count = 0;
        osaY[z].xxx = 0;
        osaY[z].count = 0;
    }
    
    int c = 0;
    for(int m = 0; m<n; m++){
        int x;
        int y ;
        int num;
        
        scanf("%d %d %d", &x, &y, &num);
        if(num>0){
            osaX[c].xxx = x;
            osaY[c].xxx = y;
            osaX[c].count = num;
            osaY[c].count = num;
            c++;
            totalPeople += num;
        }
        
        
    }
   
    //bruteforcing best score
    /*for (int i = 0; i <r; i++){
       result += i*osaX[i]; 
       distance = 0;
       for(int j = 0; j<r; j++){
        distance += abs((j-i)*osaX[j]);   
       } 
       
       if(bestScore > distance){
           bestScore = distance;
           bestI = i;
       }
      
       printf("%d-", i);
       printf("%d ", osaX[i]);
    }*/
    
    mergesort(osaX, 0, n-1);
    mergesort(osaY, 0, n-1);
    
    /*for(int t = 0; t<n; t++){
        printf("%d-%d", osaY[t].xxx, osaY[t].count);
        printf("%s ", "end");
    }*/
    int resX;
    resX = getBest(osaX, n, totalPeople);
    int resY;
    resY = getBest(osaY, n, totalPeople);
    
    printf("%d %d", resX, resY);
    
}


    


