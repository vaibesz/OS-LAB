#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void main()
{
    int tr,n,total=0,curr,min,sec_max,i,j=0,index,max;
    printf("Enter the total no of tracks in the disk:\n");
    scanf("%d",&tr);
    printf("Enter the number of requests in the request queue:\n");
    scanf("%d",&n);
    int arr[n],seek[n];
    printf("Enter the request sequence:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the current head positon of the disk arm:\n");
    scanf("%d",&curr);
    //direction considered- towards larger values first
    max=arr[0];
    min=arr[0];
    for(i=1;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    sec_max=INT_MIN;
    for(i=0;i<n;i++)
    {
        if(arr[i]<curr && arr[i]>sec_max)
        {
            sec_max=arr[i];
        }
    }
    printf("sec_max:%d\n",sec_max);
    total=(max-curr)+(max-min)+(sec_max-min);
    
    printf("Total number of movements using C-LOOK scheduling are:%d\n",total);
}
