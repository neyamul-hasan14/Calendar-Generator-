#include<stdio.h>

int getFirstDayofYear(int year){
    int day = (year * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
    return day;
}


int main ()
{
    int year;
   char *month[]={"January","February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
   int DayM[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int tday;
int wd=0;
int sp=0;

    printf("##Enter a year that you want to see the calendar##\n");

    scanf("%d",&year);

    printf("****************************welcome to %d****************************\n\n",year);



    //leap year check

    if((year%4==0 && year% 100!=0)||(year%400==0) ){
        DayM[1]=29;
    }

    wd= getFirstDayofYear(year);

    for (int i = 0; i < 12; i++) {
        printf("\n-----------------------------[%s]-----------------------------\n", month[i]);
        printf("\n    Sun    Mon    Tue    Wed    Thu    Fri    Sat\n\n");

        for(sp=1;sp<=wd;sp++){
            printf("       ");
        }

        tday=DayM[i];
        for(int j=1;j<=tday;j++){
            printf("%7d",j);
            wd++;
            if(wd>6){
                printf("\n");
                wd=0;
            }
        }
    }

    return 0;
}