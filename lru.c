#include<stdio.h>
void main(){
    int i,k,a[30],fr[30],time[30],lr,lri,n,f,count=0,avail;
    printf("Enter the number of pgs");
    scanf("%d",&n);
    printf("Enter the page values");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the number of frames");
    scanf("%d",&f);
    for(k=0;k<f;k++){
        fr[k]=-1;
        time[k]=0;
    }
    for(i=0;i<n;i++){
        avail=0;
        for(k=0;k<f;k++){
            if(fr[k]==a[i]){
                avail=1;
                time[k]=i;
                break;
            }
        }
        if(avail==0){
            if(i<f){
                fr[i]=a[i];
                time[i]=i;
            }else{
                lr=time[0];
                lri=0;
                for(k=0;k<f;k++){
                    if(time[k]<lr){
                        lr=time[k];
                        lri=k;
                    }
                }
                fr[lri]=a[i];
                time[lri]=i;
            }
            count++;
            for(k=0;k<f;k++){
                if(fr[k]!=-1){
                    printf("%d\t",fr[k]);
                }else{
                    printf("-\t");
                }
            }
          }else{
            printf("HIT");
          }
          printf("\n");
    }
printf("The page fault count is : %d",count);
}