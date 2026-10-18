// ADC INTERRUPT AND STATUS REGISTER CODE 
#include <stdint.h>
#include <stdio.h>


void print_binary(uint16_t reg){
    for(int i=13;i>=0;i--){
        putchar(((reg>>i)&1u) ? '1':'0');
        if ((i%8==0)&&i!=0){
            putchar(' ');
        }
    }
}

void check_status(uint16_t reg){
    static const char *flag[12]={
        [0]="ADRDY",
        [1]="EOSMP",
        [2]="EOC",
        [3]="EOS",
        [4]="OVR",
        [5]="JEOC",
        [6]="JEOS",
        [7]="AWD1",
        [10]="JQOVF"
    };
    printf("\n---ADC Register Staus---\n");
    for(int i=15;i>=0;i--){
        if(((reg>>i)&1u) && flag[i]!=NULL){
            printf("%s\r\n",flag[i]);
        }
    }
}

int main(){
    uint16_t temp=0;
    printf("Enter the value of reg in hex :");
    scanf("%x",&temp);
    print_binary(temp);
    check_status(temp);
    return 0;
}