#include<stdio.h>
void main()
{
    int n,x,y,z;
    printf("Enter the number of processes");
    scanf("%d",&n);
    int p[n],bt[n],wt[n],tat[n],prio[n];
    float awt=0, att=0;
    for(int i=0;i<n;i++){
    printf("Enter the pid, bt and prio of process %d",i+1);
    scanf("%d%d%d",&p[i],&bt[i],&prio[i]);
    } 
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(prio[j]>prio[j+1]){
                x=prio[j];
                prio[j]=prio[j+1];
                prio[j+1]=x;
                y=p[j];
                p[j]=p[j+1];
                p[j+1]=y;
                z=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=z;
            } } }
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
        awt+=wt[i];
    }
    for(int i=0;i<n;i++){
        tat[i]=wt[i]+bt[i];
        att+=tat[i];
    }
    printf("prcs\tprio\tbt\twt\ttat\t\n");
    for(int i=0;i<n;i++){
    printf("%d\t%d\t%d\t%d\t%d\t\n",p[i],prio[i],bt[i],wt[i],tat[i]);
    }
    printf("avg wt=%f\n",awt/n);
    printf("avg tat=%d\n",att/n);
printf("GANTT CHART\n");
for(int i=0;i<n;i++){
    printf("   p[%d]\t",p[i]);
}
int temp=0;
printf("\n\n0\t");
for(int i=0;i<n;i++){ 
    temp=temp+bt[i];
    printf("%d\t",temp); 
}

}