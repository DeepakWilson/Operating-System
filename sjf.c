#include<stdio.h>
void main(){
    int i,j,bt[50],wt[50],tat[50],p[10],n;
    float att=0,awt=0;
    printf("Enter the number of processes");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter the process id for process %d",i);
        scanf("%d",&p[i]);
    }
    for(i=0;i<n;i++){
        printf("Enter burst time of p%d: ",p[i]);
        scanf("%d",&bt[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(bt[j]>bt[j+1]){
                int temp=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=temp;
                
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }}}
    wt[0]=0;
    for(i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
        awt+=bt[i];
    }
    for(i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
        att+=tat[i];
    }
    printf("PID\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++){
        printf("%d    \t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
    }
    printf("Avg WT=%f\nAvg TAT=%f",awt/n,att/n);
    printf("\nGANTT CHART\n");
    for(i=0;i<n;i++)
    printf("    [p%d]\t",p[i]);
    printf("\n");
    printf("0\t");
    for(i=0;i<n;i++)
    printf("%d\t",bt[i]);

}
