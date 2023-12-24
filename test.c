#include <stdio.h>
#include <math.h>

int c = 0,numa[8]={0},numb[8]={0},diff[8]={0},sum[8]={0};
void add();
void sub();
void main(){
            int ch;
            do{
            for(int i=0; i<8; i++){
                        numa[i] = 0;
                        numb[i] = 0;
                        diff[i] = 0;
                        sum[i] = 0;
            }
            c = 0;
            printf("\tADDITION-SUBTRACTION USING TWO'S COMPLEMENT");
            printf("\n1.ADD\n2.SUBTRACT\nEnter your choice: ");
            scanf("%d",&ch);
                        switch(ch){
                                    case 1: add();
                                                break;
                                    case 2: sub();
                                                break;
                                    default: printf("\nInvalid Choice: ");
                        }
            printf("\nPress 1 to Continue...");
            scanf("%d",&ch);
            }while(ch == 1);
}
void add(){
            printf("\nEnter two 8-bit binary numbers\n");
            printf("\nEnter first number: ");
            for(int i = 0; i<8; i++){
                        scanf("%d",&numa[i]);
            }
            printf("\nEnter second number: ");
            for(int i = 0; i<8; i++){
                        scanf("%d",&numb[i]);
            }
            for(int i = 7; i >= 0; i--){
                        sum[i] = numa[i]+ numb[i] + c;
                        if(sum[i]>=2){
                                    c = 1;
                        }
                        else
                                    c = 0;
                        sum[i] = sum[i]%2;
            }
            printf("\nSum is: ");
            for(int i = 0; i<8; i++){
                        printf("%d",sum[i]);
            }
}
void sub(){
            printf("\nEnter two 8-bit binary numbers\n");
            printf("\nEnter first number: ");
            for(int i = 0; i<8; i++){
                        scanf("%d",&numa[i]);
            }
            printf("\nEnter second number: ");
            for(int i = 0; i<8; i++){
                        scanf("%d",&numb[i]);
            }
            for(int i = 7; i >= 0; i--){
                        diff[i] = numa[i] - numb[i];
                        if(diff[i] < 0){
                                    numa[i-1] = numa[i-1] - 1;
                        }
                        diff[i] = fabs(diff[i]%2);
            }
            printf("\nDifference is: ");
            for(int i = 0; i<8; i++){
                        printf("%d",diff[i]);
            }
}