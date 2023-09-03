#include <stdio.h>
#include <stdlib.h>
int main()
{
    int request[10], i, j, n, initial, size, move, totalhm = 0;
    printf("enter the number of requests\n");
    scanf("%d", &n);
    printf("enter the requests sequence\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &request[i]);
    }
    printf("enter the initial head position\n");
    scanf("%d", &initial);
    printf("enter the total disk size\n");
    scanf("%d", &size);
    printf("enter the head movement direction for high 1 and for low 0\n");
    scanf("%d", &move);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (request[j] > request[j + 1])
            {
                int temp;
                temp = request[j];
                request[j] = request[j + 1];
                request[j + 1] = temp;
            }
        }
    }
    int index;
    for (i = 0; i < n; i++)
    {
        if (initial == request[i])
        {
            index = i;
            break;
        }
    }
    if (move == 1)
    {
        printf("Disk sequence is: ");
        printf("%d", initial);
        for (i = index + 1; i < n; i++)
        {
            totalhm += ((request[i]) - initial);
            initial = request[i];
            printf("==>%d", initial);
        }
        totalhm += (size - (request[i - 1]) - 1);
        initial = size - 1;
        printf("==>%d", initial);
        totalhm += size - 1;
        initial=0;
        printf("==>%d", initial);
        for (i =0 ; i<index; i++)
        {
            totalhm += ((request[i]) - initial);
            initial = request[i];
            printf("==>%d", initial);
        }
        printf("\n");
    }
    else
    {
        printf("Disk sequence is: ");
        printf("%d", initial);
        for (i = index - 1; i >= 0; i--)
        {
            totalhm -= ((request[i]) - initial);
            initial = request[i];
            printf("==>%d", initial);
        }
        totalhm += (request[i + 1]);
        initial = 0;
        printf("==>%d", initial);
        totalhm += size-1;
        initial=size-1;
        printf("==>%d", initial);
        for (i = n-1; i > index; i--)
        {
            totalhm -= ((request[i]) - initial);
            initial = request[i];
            printf("==>%d", initial);
        }
        printf("\n");
    }
    printf("total head movement is %d", totalhm);
    return 0;
}

