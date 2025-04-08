#include<stdio.h>
void main(){
    int i,j,k=0,r,n,flag=0,exec,c=0;
    printf("Enter the number of processes");
    scanf("%d",&n);
    printf("Enter the number of resources");
    scanf("%d",&r);
    int alloc[50][50],max[50][50],ss[50],need[50][50],visit[50],avail[50];
    printf("Enter the available matrix");
    for(j=0;j<r;j++){
    scanf("%d",&avail[j]);
    }
    for(i=0;i<n;i++){
        visit[i]=0;
        printf("Enter the max matrix of p%d",i);
        for(j=0;j<r;j++)
        scanf("%d",&max[i][j]);
        printf("Enter the alloc matrix of p%d",i);
        for(j=0;j<r;j++){
        scanf("%d",&alloc[i][j]);
        need[i][j]=max[i][j]-alloc[i][j];
        } 
    }
    printf("\nAllocation\tMax\t\tNeed\n");
for(i=0;i<n;i++) {
for(j=0;j<r;j++)
printf("%d ",alloc[i][j]);
printf("\t\t");
for(j=0;j<r;j++)
printf("%d ",max[i][j]);
printf("\t\t");
for(j=0;j<r;j++)
printf("%d ",need[i][j]);
printf("\n");

    }
    while(c<n){
        flag=0;
        for(i=0;i<n;i++){
            exec=0;
            for(j=0;j<r;j++){
                if(need[i][j]<=avail[j]){
                    exec++;
                }
            }
                if(visit[i]==0 && exec==r){
                    visit[i]=1;
                    for(j=0;j<r;j++)
                    avail[j]+=alloc[i][j];
                    flag=1;
                    c++;
                    ss[k++]=i;
            }
        }
        if(flag==0){
            printf("No safe sequence");
            return;
        }
    }
    printf("\nSafe sequence=\t");
    for(i=0;i<n;i++)
    printf("P%d\t",ss[i]);

}
