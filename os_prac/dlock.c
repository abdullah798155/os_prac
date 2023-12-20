#include<stdio.h>
int main(){
        int m,n;
        printf("Enter the no of resources\n");
        scanf("%d",&n);
        printf("Enter the no of processes\n");
        scanf("%d",&m);
        int ma[n];
        printf("Enter the max instances of each resource\n");
        for(int i=0;i<n;i++) scanf("%d",&ma[i]);
        int max[m][n];
        int alloc[m][n];
        int avail[n];
        for(int j=0;j<n;j++) avail[j] = 0;
        printf("Enter the allocation matrix\n");
        for(int i=0;i<m;i++){
                printf("For P%d: ",i+1);
                for(int j = 0;j<n;j++){
                        scanf("%d",&alloc[i][j]);
                        avail[j] += alloc[i][j];
                }
        }
        for(int j=0;j<n;j++){
                avail[j] = ma[j] - avail[j];
        }
        int need[m][n];
        printf("Enter max need of each process\n");
        for(int i=0;i<m;i++){
                printf("For P%d: ",i+1);
                for(int j = 0;j<n;j++){
                        scanf("%d",&max[i][j]);
                        need[i][j] = max[i][j] - alloc[i][j];
                }
        }
        int seq[n],t=0,f[m],fail[m];
        for(int i=0;i<m;i++) f[i] = 0;
A:
        for(int i=0;i<m;i++){
                int count = 0;
                for(int j=0;j<n;j++){
                        if(need[i][j] <= avail[j] && f[i] == 0) count++;
                }
                if(count == n){
                        f[i] = 1;
                        seq[t++] = i+1;
                        for(int k=0;k<n;k++) avail[k] += alloc[i][k];
                }
        }
        if(t!=m) goto A;
        for(int i=0;i<t;i++) printf("P%d -> ",seq[i]);
}