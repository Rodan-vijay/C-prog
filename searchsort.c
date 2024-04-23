// Online C compiler to run C program online
#include <stdio.h>
int len;
int lsearch(int arr[], int target)
{
 for(int i=0;i<len;i++)
 if(arr[i]==target)
 {
     printf("the rq ind is :"%d,i);
     return 0;
 }
 printf("The elemnet is not fnd");
    
}
void b_search(int arr[],int low,int high,int target)
{ int mid;
mid=(low+high)/2;
    if (low>high)
        printf("The element is not fnd");
    else if (arr[mid]==target)
        printf("the req ind is : %d",mid);
    else if (target>arr[mid])
        b_search(arr,mid+1,high,target);
    else if (target<arr[mid])
        b_search(arr,low,mid-1,target);
    
}
void bsort(int arr[])
{   int temp;
    for (int i=0;i<len;i++)
        for(int j=0;j<len-1-i;j++)
            if(arr[j]>arr[j+1])
                {
                    temp=arr[j];arr[j]=arr[j+1];arr[j+1]=temp;
                }    
    
    
}
void ssort(int arr[])
{
    int min_ind,temp;
    for(int i=0;i<len;i++)
        {
            min_ind=i;
            for(int j=i+1;j<len;j++)
                if(arr[min_ind]>arr[j])
                        min_ind=j;
                 temp=arr[min_ind];
                 arr[min_ind]=arr[i];
                 arr[i]=temp;
        }
        
}
int main() {
    // Write C code here
    printf("Try programiz.pro");
    printf("\nenter the lengt : ");
    scanf("%d",&len);
    printf("Enter the elemnts :\n");
    int arr[len];
    for (int i=0;i<len;i++)
        scanf("%d",&arr[i]);
    printf("Ente the target : ");
    int target;
    scanf("%d",&target);
    lsearch(arr,target);
    ssort(arr);
    printf("\n");
    for (int i=0;i<len;i++)
        printf("%d",arr[i]);
    printf("\n");
    bsort(arr);
    for (int i=0;i<len;i++)
         printf("%d",arr[i]);
    printf("\n");
    b_search(arr,0,len-1,target);

    return 0;
}