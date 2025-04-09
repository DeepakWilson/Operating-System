#include<stdio.h>
void main(){
    int memblock,limit;
    printf("Enter the number of memoryblocks");
    scanf("%d",&memblock);
    printf("Enter the number of processes");
    scanf("%d",&limit);
    struct memory{
        int size,alloc;
    }m[memblock];
    printf("Enter memory of each blocks");
    for(int i=0;i<memblock;i++){
        scanf("%d",&m[i].size);
        m[i].alloc=0;
    }
    struct process{
        int psize,flag;
    }p[limit];
    printf("Enter the size of processes");
    for(int i=0;i<limit;i++){
        scanf("%d",&p[i].psize);
        p[i].flag=0;
    }
printf("process\tprocess size\tblock size\t\n");
for(int i=0;i<limit;i++){
    for(int j=0;j<memblock;j++){
        if(p[i].flag==0){
            if(p[i].psize<=m[j].size){
                if(m[j].alloc==1){
                continue;
                }else{
                    m[j].alloc=1;
                    p[i].flag=1;
                     printf("\t%d\t\t%d\t\t%d\n", i + 1, p[i].psize, m[j].size);
                    break;
                }

            }
        }
    }
}
for (int i = 0; i < limit; i++) {
    if (p[i].flag == 0) { 
        printf("\n\tThere is no space for process %d with size %d\n", i + 1, p[i].psize);
    }
}
}