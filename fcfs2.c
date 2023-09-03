#include <stdio.h>
#include <stdlib.h>
struct process
{
    int pid, arrival_time, burst_time, completion_time, turnaround_time, waiting_time;
} p[25];
struct process temp;
void print_gantt_chart(int n);
void print_table(int n);
void avg_TAT_WT(int n);
int main()
{
    int i, j, n;
    printf("Enter the total no of processes");
    scanf("%d", &n);
    printf("Enter the arrival time for each process");
    for (i = 0; i < n; i++)
    {
        p[i].pid = i;
        printf("P[%d]", i);
        scanf("%d", &p[i].arrival_time);
        p[i].waiting_time = p[i].turnaround_time = 0;
    }
    printf("Enter the burst time for each process");
    for (i = 0; i < n; i++)
    {
        printf("P[%d]", i);
        scanf("%d", &p[i].burst_time);
    }
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (p[j].arrival_time > p[j + 1].arrival_time)
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
    p[0].completion_time = p[0].arrival_time + p[0].burst_time;
    p[0].turnaround_time = p[0].completion_time - p[0].arrival_time;
    p[0].waiting_time = 0;
    for (i = 1; i < n; i++)
    {
        p[i].completion_time = p[i - 1].completion_time + p[i].burst_time;
        p[i].turnaround_time = p[i].completion_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
    }
    printf("\n");
    print_gantt_chart(n);
    printf("\n");
    print_table(n);
    printf("\n");
    avg_TAT_WT(n);
    return 0;
}

void print_gantt_chart(int n)
{
    int i;
    printf("GANTT CHART\n");
    for (i = 0; i < n; i++)
        printf("-----");
    printf("-\n");
    for (i = 0; i < n; i++)
        printf("|P[%d]", p[i].pid);
    printf("|\n");
    for (i = 0; i < n; i++)
        printf("-----");
    printf("-\n");
    printf("%d", p[i].arrival_time);
    for (i = 0; i < n; i++)
        printf("    %d", p[i].completion_time);
    printf("\n");
}

void print_table(int n)
{
    int i;
    printf("-------------------------------------------------------------------------------------\n");
    printf("|PID | ARRIVAL TIME | BURST TIME | COMPLETION TIME | TURNAROUND TIME | WAITING TIME | \n");
    printf("-------------------------------------------------------------------------------------\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
    }
    printf("-------------------------------------------------------------------------------------\n");
}

void avg_TAT_WT(int n)
{
    int sum_waiting_time = 0, sum_turnaround_time = 0;
    float average_waiting_time, average_turnaround_time;
    for (int i = 0; i < n; i++)
    {
        sum_waiting_time += p[i].waiting_time;
        sum_turnaround_time += p[i].turnaround_time;
    }
    average_waiting_time = (float)sum_waiting_time / n;
    average_turnaround_time = (float)sum_turnaround_time / n;
    printf("Average waiting time=%f\n", average_waiting_time);
    printf("Average turnaround time=%f\n", average_turnaround_time);
}
