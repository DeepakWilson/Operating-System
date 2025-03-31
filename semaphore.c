#include<stdio.h>
#include<stdlib.h>
    int mutex=1, full=0, empty=3;
    int wait(int s){
        s--;
        return s;
    }
    int signal(int s){
        s++;
        return s;
    }
    void producer(){
        mutex= wait(mutex);
        full=signal(full);
        empty=wait(empty);
        mutex=signal(mutex);
    }
    void consumer(){
        mutex=wait(mutex);
        full=wait(full);
        empty=signal(empty);
        mutex=signal(mutex);
    }
    int main(){
        int ch;
          do{
        printf("\nEnter the desired choice");
        printf("\n1.Producer\t2.Consumer\t3.Exit\n");
        scanf("%d",&ch);
            switch(ch){
                case 1: if(mutex==1 && empty!=0){
                producer();
                printf("successfully produced");
                }else{
                    printf("Not possible");
                }
                break;
                case 2: if(mutex==1 && full!=0){
                    consumer();
                    printf("successfully consumed");
                }else{
                    printf("Not possible");
                }
                break;
                case 3: exit(0);
                default: printf("Pick available options");
                break;
            }
        }while(ch!=3);
        }
