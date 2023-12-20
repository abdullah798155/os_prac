#include<stdio.h>  
#include<conio.h>  

void main() {  
    int i, NOP, sum=0, count=0, y, quantum, wt=0, tat=0, at[10], bt[10], temp[10];  
    float avg_wt, avg_tat;  

    printf("Total number of processes: ");  
    scanf("%d", &NOP);  
    y = NOP;

    for(i=0; i<NOP; i++) {
        printf("Arrival time for P[%d]: ", i+1);  
        scanf("%d", &at[i]);  
        printf("Burst time for P[%d]: ", i+1); 
        scanf("%d", &bt[i]);  
        temp[i] = bt[i];  
    }  
    
    printf("Enter the Time Quantum: ");  
    scanf("%d", &quantum);  

    printf("\nP\tBT\tTAT\tWT");  
    
    for(sum=0, i = 0; y!=0; ) {  
        if(temp[i] <= quantum && temp[i] > 0) {  
            sum += temp[i];  
            temp[i] = 0;  
            count=1;  
        } else if(temp[i] > 0) {  
            sum += quantum;    
            temp[i] -= quantum;  
        }  
        
        if(temp[i]==0 && count==1) {  
            y--;  
            printf("\nP[%d]\t%d\t%d\t%d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);  
            wt += sum-at[i]-bt[i];  
            tat += sum-at[i];  
            count =0;     
        }  
        
        if(i==NOP-1) {  
            i=0;  
        } else if(at[i+1] <= sum) {  
            i++;  
        } else {  
            i=0;  
        }  
    }  
    
    avg_wt = wt * 1.0 / NOP;  
    avg_tat = tat * 1.0 / NOP;  
    
    printf("\nAvg TAT: \t%.2f", avg_wt);  
    printf("\nAvg WT: \t%.2f", avg_tat);  

    getch();  
}
