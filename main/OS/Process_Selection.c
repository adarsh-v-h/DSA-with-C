#include <stdio.h>
#include <stdlib.h>
void FCFS();
void SJF();
void priority();
void roundrobin();
void SRTF();

int main(){
    int choice;
    while(1){
        printf("\n=============================================\n");
        printf(" CPU Scheduling Algorithms Simulation\n");
        printf("=============================================\n");
        printf("1. FCFS\n");
        printf("2. Round Robin\n");
        printf("3. SJF\n");
        printf("4. Priority\n");
        printf("5. SRTF\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: FCFS(); break;
            case 2: roundrobin(); break;
            case 3: SJF(); break;
            case 4: priority(); break;
            case 5: SRTF(); break;
            case 6: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void FCFS(){
    int i, n, waiting[10], turnaround[10], burst[10];
    int totalwaiting=0, totalturnaround=0;
    float avgwaiting = 0.0, avgturnaround = 0.0;

    printf("\n--- FCFS Scheduling Algorithm ---\n");
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the burst times: ");
    for(i=0; i <n; i++)
        scanf("%d", &burst[i]);

    waiting[0] = 0;
    turnaround[0] = burst[0];

    for(i=1; i <n; i++){
        turnaround[i] = turnaround[i-1] + burst[i];
        waiting[i] = turnaround[i] - burst[i];
    }

    for(i=0; i <n; i++){
        totalwaiting += waiting[i];
        totalturnaround += turnaround[i];
    }

    avgwaiting = (float)totalwaiting / n;
    avgturnaround = (float)totalturnaround / n;

    printf("\nPROCESS\tBURST\tWAITING\tTURNAROUND\n");
    for(i=0; i <n; i++)
        printf("P%d\t%d\t%d\t%d\n", i+1, burst[i], waiting[i], turnaround[i]);

    printf("\nAverage Waiting Time: %.2f", avgwaiting);
    printf("\nAverage Turnaround Time: %.2f\n", avgturnaround);
}

void SJF(){
    int n, i, j, pos, waiting[10], turnaround[10], burst[10], p[10];
    int totalwaiting=0, totalturnaround=0;
    float avgwaiting = 0, avgturnaround = 0;

    printf("\n--- Shortest Job First (SJF) ---\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times: ");
    for(i=0; i <n; i++){
        scanf("%d", &burst[i]);
        p[i] = i + 1;
    }

    for(i=0; i <n; i++){
        pos = i;
        for(j=i+1; j <n; j++){
            if(burst[j]  < burst[pos])
                pos = j;
            }
        int temp = burst[i];
        burst[i] = burst[pos];
        burst[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    waiting[0] = 0;

    turnaround[0] = burst[0];

    for(i=1; i <n; i++){
        turnaround[i] = turnaround[i-1] + burst[i];
        waiting[i] = turnaround[i] - burst[i];
    }

    for(i=0; i <n; i++){
        totalwaiting += waiting[i];
        totalturnaround += turnaround[i];
    }

    avgwaiting = (float)totalwaiting / n;
    avgturnaround = (float)totalturnaround / n;

    printf("\nPROCESS\tBURST\tWAITING\tTURNAROUND\n");
    for(i=0; i <n; i++)
        printf("P%d\t%d\t%d\t%d\n", p[i], burst[i], waiting[i], turnaround[i]);

    printf("\nAverage Waiting Time: %.2f", avgwaiting);
    printf("\nAverage Turnaround Time: %.2f\n", avgturnaround);
}

void priority(){
    int i, j, n, waiting[10], turnaround[10], pr[10], burst[10], p[10];
    int totalwaiting=0, totalturnaround=0, pos, temp;

    float avgwaiting = 0.0, avgturnaround = 0.0;

    printf("\n--- Priority Scheduling ---\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i=0; i <n; i++){
        printf("Enter burst time for P%d: ", i+1);
        scanf("%d", &burst[i]);
        printf("Enter priority for P%d: ", i+1);
        scanf("%d", &pr[i]);
        p[i] = i + 1;
    }

    for(i=0; i <n; i++)
    {
        pos = i;
        for(j=i+1; j <n; j++)
        {
            if(pr[j]  < pr[pos])
                pos = j;
        }
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;

        temp = burst[i];
        burst[i] = burst[pos];

        burst[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    waiting[0] = 0;
    turnaround[0] = burst[0];

    for(i=1; i <n; i++)
    {
        turnaround[i] = turnaround[i-1] + burst[i];
        waiting[i] = turnaround[i] - burst[i];
    }

    for(i=0; i <n; i++)
    {
        totalwaiting += waiting[i];
        totalturnaround += turnaround[i];
    }

    avgwaiting = (float)totalwaiting / n;
    avgturnaround = (float)totalturnaround / n;

    printf("\nPROCESS\tPRIORITY\tBURST\tWAITING\tTURNAROUND\n");
    for(i=0; i <n; i++)
    printf("P%d\t%d\t\t%d\t%d\t%d\n", p[i], pr[i], burst[i], waiting[i], turnaround[i]);

    printf("\nAverage Waiting Time: %.2f", avgwaiting);
    printf("\nAverage Turnaround Time: %.2f\n", avgturnaround);
}

void roundrobin()
{
    int n, quantum, burst[10], remburst[10], turnaround[10], waiting[10];
    int i, count, sq=0, totalwaiting=0, totalturnaround=0, temp1;
    float avgwaiting=0.0, avgturnaround=0.0;

    printf("\n--- Round Robin Scheduling ---\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times: ");
    for(i=0; i <n; i++)
    {
        scanf("%d", &burst[i]);
        remburst[i] = burst[i];
        turnaround[i] = 0;
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    while(1)
    {
        count = 0;
        for(i=0; i <n; i++)

        {
        if(remburst[i] == 0)
        {
            count++;
            continue;
        }

        if(remburst[i] > quantum)
            temp1 = quantum;
        else
            temp1 = remburst[i];

        remburst[i] -= temp1;
        sq += temp1;
        turnaround[i] = sq;
        }
        if(count == n)
        break;
    }

    for(i=0; i <n; i++)
    {
        waiting[i] = turnaround[i] - burst[i];
        totalwaiting += waiting[i];
        totalturnaround += turnaround[i];
    }

    avgwaiting = (float)totalwaiting / n;
    avgturnaround = (float)totalturnaround / n;

    printf("\nPROCESS\tBURST\tWAITING\tTURNAROUND\n");
    for(i=0; i <n; i++)
        printf("P%d\t%d\t%d\t%d\n", i+1, burst[i], waiting[i], turnaround[i]);

    printf("\nAverage Waiting Time: %.2f", avgwaiting);
    printf("\nAverage Turnaround Time: %.2f\n", avgturnaround);
}

void SRTF()
{
    int n, i, time=0, smallest, endtime, remain=0;
    int arrivaltime[10], bursttime[10], rt[10];
    int swt=0, stat=0;
    float awt=0.0, atat=0.0;

    printf("\n--- Shortest Remaining Time First (SRTF) ---\n");
    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i=0; i <n; i++)
    {
        printf("Enter arrival time for P%d: ", i+1);
        scanf("%d", &arrivaltime[i]);
        printf("Enter burst time for P%d: ", i+1);
        scanf("%d", &bursttime[i]);
        rt[i] = bursttime[i];
    }

    rt[9] = 999; // sentinel large value
    printf("\nPROCESS\tWAITING\tTURNAROUND\n");

    for(time=0; remain != n; time++)
    {
        smallest = 9;
        for(i=0; i <n; i++)
        {
            if(arrivaltime[i]  <= time && rt[i]  < rt[smallest] && rt[i] > 0)
                smallest = i;
        }
        rt[smallest]--;
        if(rt[smallest] == 0)
        {
            remain++;
            endtime = time + 1;
            printf("P%d\t%d\t%d\n", smallest+1,
            endtime - bursttime[smallest] - arrivaltime[smallest],
            endtime - arrivaltime[smallest]);

            swt += endtime - bursttime[smallest] - arrivaltime[smallest];
            stat += endtime - arrivaltime[smallest];
        }
    }

    awt = (float)swt / n;
    atat = (float)stat / n;

    printf("\nAverage Waiting Time: %.2f", awt);

    printf("\nAverage Turnaround Time: %.2f\n", atat);
}