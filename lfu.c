#include<stdio.h>
void main(){
    int i,k,n,f,a[30],fr[30],freq[30],avail,pgflt=0;
    printf("Enter the number of pages");
    scanf("%d",&n);
    printf("Enter the pg values");
    for(i=0;i<n;i++){
    scanf("%d",&a[i]);
    }
    printf("Enter the number of frames");
    scanf("%d",&f);
    for(k=0;k<f;k++){
        fr[k]=-1;
        freq[k]=0; 
    }
    for(i=0;i<n;i++){
        avail=0;
        for(k=0;k<f;k++){
            if(fr[k]==a[i]){
                avail=1;
                freq[k]++;
                break;
            }
        }
        if(avail==0){
            int minindex=0,minfreq=freq[0];
            if(i<f){
                fr[i]=i;
                freq[i]++;
            }else{
                for(k=0;k<f;k++){
                    if(freq[k]<minfreq){
                        minfreq=freq[k];
                        minindex=k;

                    }
                }
                fr[minindex]=a[i];
                freq[minindex]=1;
            }
            pgflt++;
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
printf("The page fault count is : %d",pgflt);
}