#include<stdio.h>
void main(){
    int n;
    float awt=0,att=0;
    printf("Enter the number of processes");
    scanf("%d",&n);
    int wt[n],bt[n],tat[n];
    for(int i=0;i<n;i++){
         printf("Enter the bt of process %d",i+1);
         scanf("%d",&bt[i]);
    }
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+ bt[i-1];
        awt+=wt[i];
    }
    for(int i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
        att+=tat[i];
    }
printf("PROCESS\tBT\tWT\tTAT\n");
for(int i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
}
printf("Avg wt=%f\n",awt/n);
printf("Avg tat=%f\n",att/n); 
/*GANTT*/
printf("Fantt Chart\n");
for(int i=0;i<n;i++){
    printf("\t P[%d]",i+1);
}
    printf("\n\t\n");
int temp=0;
printf("\t0");
for(int i=0;i<n;i++){
    temp+=bt[i];
    printf("\t%d",temp);
}
}