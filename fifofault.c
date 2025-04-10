#include<stdio.h>
void main(){
    int count=0,n,k,a[10],f,m[10],pf=0;
    printf("Enter the no of page"); 
    scanf("%d",&n);
    printf("Enter the page values");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Enter the number of frames");
    scanf("%d",&f);
    for(int i=0;i<f;i++){
        m[i]=-1;
    }
    for(int i=0;i<n;i++){
        for(k=0;k<f;k++){
            if(m[k]==a[i]){
                break;
            }
        }
        if(k==f){
            m[count]=a[i];
            count= (count+ 1)%f;
            pf++;
        }
        for(int j=0;j<f;j++){
            printf("%d\t",m[j]);
        }            printf("\n");


    }
    printf("Page Fault= %d",pf);

}