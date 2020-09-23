#include <stdio.h>

void swap (int* a, int* b, int * c, int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    
    temp = b[i];
    b[i] = b[j];
    b[j] = temp;
    
    temp = c[i];
    c[i] = c[j];
    c[j] = temp;
}

void sort (int* bt, int* at, int * ind, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if ((at[j] > at[j + 1]) || (at[j] == at[j + 1] && bt[j] > bt[j + 1]))
                swap(bt, at, ind, j, j + 1);
        }
    }
}

int main()
{
    int n;
    printf("Enter total number of processes: ");
    scanf("%d",&n);
    printf("\nPlease, be informed that you should write numbers in order, not randomly. Thanks!\n");
    int ind[n], at[n], bt[n], wt[n], tat[n], ct;
    float avgwt = 0, avgtat = 0;
 
    for(int i = 0; i < n; i++) {
        printf("Enter arrival time of the process %d: ", i+1);
        scanf("%d", &at[i]);
        printf("Enter burst time of the process %d: ", i+1);
        scanf("%d", &bt[i]);
        ind[i] = i + 1;
    }
    
    sort(bt, at, ind, n);
 
    wt[0] = 0; //waiting time
    ct = 0;
    tat[0] = bt[0]; //turn around time
    
    for(int i = 1; i<n; i++) {
        wt[i]=0;
        for(int j=0; j<i; j++){
            wt[i] += bt[j];
        }
        wt[i] -= at[i]-1;
        tat[i] = bt[i] + wt[i];
    }

    for(int i = 0; i < n; i++){
        ct = ct + bt[i];
        avgwt += wt[i];
        avgtat += tat[i];
        printf("For P%d: \nArrival Time = %d\nBurst Time = %d\nCompletion Time = %d\nWaiting Time = %d\nTurnaround Time = %d\n\n", ind[i], at[i], bt[i], ct, wt[i], tat[i]);
    }
 
    printf("\n\nAverage Waiting Time: %f", avgwt/n);
    printf("\nAverage Turnaround Time: %f", avgtat/n);
 
    return 0;
}
