#include<stdio.h>
#include<stdlib.h>
void main()
{
    int n_p,n_b,p[10],bsort[10],b[10],rem_b[10],b_alloc[10],i,j;
    int flag=0;
    int ch,temp;
    printf("Enter the number of memory blocks");
    scanf("%d",&n_b);
    printf("Enter the memory block sizes:");
    for(i=0;i<n_b;i++)
    {
        scanf("%d",&b[i]);
        bsort[i]=i;
        rem_b[i]=b[i];
        b_alloc[i]=-1;
    }
    printf("Enter the number of processes");
    scanf("%d",&n_p);
    printf("Enter the process sizes:");
    for(i=0;i<n_p;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("BLOCK\tSIZE\n");
    for(i=0;i<n_b;i++)
        printf("%d\t%d\n",i+1,b[i]);
    printf("PROCESS\tSIZE\n");
    for(i=0;i<n_p;i++)
        printf("%d\t%d\n",i+1,p[i]);
    for(i=0;i<n_b;i++)
    {
        for(j=0;j<n_b-i-1;j++)
        {
            if(b[bsort[j]]>b[bsort[j+1]])
            {
                temp=bsort[j];
                bsort[j]=bsort[j+1];
                bsort[j+1]=temp;
            }
        }
    }
    printf("\n\nMENU\n 1.FIRST FIT\n 2.WORST FIT\n 3.BEST FIT\n SELECT CHOICE:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        for(i=0;i<n_p;i++)
        {
            flag=1;
            for(j=0;j<n_b;j++)
            {
                if(p[i]<=rem_b[j])
                {
                    rem_b[j]=0;
                    b_alloc[j]=i+1;
                    flag=0;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        break;
    case 2:
        for(i=0;i<n_p;i++)
        {
            flag=1;
            for(j=n_b-1;j>=0;j--)
            {
                if(p[i]<=rem_b[bsort[j]])
                {
                    rem_b[bsort[j]]=0;
                    b_alloc[bsort[j]]=i+1;
                    flag=0;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        break;
    case 3:
        for(i=0;i<n_p;i++)
        {
            flag=1;
            for(j=0;j<n_b;j++)
            {
                if(p[i]<=rem_b[bsort[j]])
                {
                    rem_b[bsort[j]]=0;
                    b_alloc[bsort[j]]=i+1;
                    flag=0;
                    break;
                }
            }
            if(flag==1)
                break;
        }
        break;
    default:
        printf("\nINVALID CHOICE\n\n");
    exit(0);
    }
    printf("\n\nBLOCK\tSIZE\tALLOCATED PROCESSES\n");
    for(i=0;i<n_b;i++)
    {
        printf("%d\t%d\t",i+1,b[i]);
        if(b_alloc[i]>-1)
        {
            printf("%d\n",b_alloc[i]);
        }
        else
        {
            printf("-\n");
        }
    }
    printf("\nUNALLOCATED PROCESS NUMBERS=");
    for(i=0;i<n_p;i++)
    {
        flag=0;
        for(j=0;j<n_b;j++)
        {
            if(b_alloc[j]==i+1)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
            printf("%d",i+1);
    }
    printf("\n\n");
}
