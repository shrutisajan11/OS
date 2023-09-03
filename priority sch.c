#include<stdio.h>
struct PCB
{
    int processid,at,bt,tat,wt,ct,priority;
};
void pline(int x);
void main()
{
    int i,num,j,n,a[10],c,l,pos;
    float avg=0.0,sum=0.0,avg1=0.0,sum1=0.0,avg2=0.0,sum2=0.0;
    struct PCB p[10],temp;
    printf("enter total no. of process");
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        printf("enter arrival time ,priority and burst time of the processor");
        scanf("%d %d %d",&p[i].at,&p[i].priority,&p[i].bt);
        p[i].processid=i+1;
    }
        for(i=0;i<num-1;i++)
        {
            for(j=0;j<num-i-1;j++)
            {
                if(p[j].at>p[j+1].at)
                {
                    temp=p[j];
                    p[j]=p[j+1];
                    p[j+1]=temp;
                }
            }
        }
         for(i=1;i<num-1;i++)
        {
            pos=i;
            for(j=i+1;j<num;j++)
            {
                if(p[pos].priority>p[j].priority)
                {
                    pos=j;
                }
            }
                if(pos!=i)
                {
                    temp=p[i];
                    p[i]=p[pos];
                    p[pos]=temp;
                }

        }

sum=p[0].at;
    for(i=0;i<num;i++)
    {
        sum=sum+p[i].bt;
        p[i].ct=sum;
        p[i].tat=p[i].ct-p[i].at;
        p[i].wt=p[i].tat-p[i].bt;
        sum1=sum1+p[i].wt;
        sum2=sum2+p[i].tat;
    }
    pline(100);
    printf("PID\tPriority  Arrival time\tBurst time\tCompletion time\t Waiting time\t Turnaround time\n");
    pline(100);
    for(i=0;i<num;i++)
    {
        printf("%d\t%d\t  %d\t\t%d\t\t\t%d\t\t%d\t\t%d\t\n",p[i].processid,p[i].priority,p[i].at,p[i].bt,p[i].ct,p[i].wt,p[i].tat);
    }
    pline(100);
    avg1=sum1/(float)num;
    avg2=sum2/(float)num;
    printf("\n Total waiting time :%f.",sum1);
    printf("\n Average waiting time :%.3f.",avg1);
    printf("\n Total turnaround time :%f.",sum2);
    printf("\n Average turnaround time :%.3f.",avg2);
    l=p[0].at;
    for(i=0;i<num;i++)
    {
        if(l>p[i].at)
        l=p[i].at;
    }
    printf("\nGantt Chart :\n");
    printf("\t+");
    for(i=0;i<num;i++)
    printf("-------+");
    printf("\n");
    printf("\t|");
    for(i=0;i<num;i++)
    printf("   %d   |",p[i].processid);
    printf("\n");
    printf("\t+");
    for(i=0;i<num;i++)
    printf("-------+");
    printf("\n\t%d",l);
    c=l;
    for(i=0;i<num;i++)
    {
        c=c+p[i].bt;
        printf("\t%d",c);
    }
    printf("\n\n");

}
void pline(int x)
{
    int i;
    for(i=0;i<x;i++)
    {
    printf("-");
    }
    printf("\n");
}
