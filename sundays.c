/**
 * @file sundays.c
 *
 * @author Jade Baca
 *
 * @date 10/13/16
 *
 * Assignment: Lab 5
 *
 * @brief Calculates the number of Sundays on
 * a Monday from 1901 to 2000.
 *
 * @bugs not that I found
 *
 **/
#include <stdio.h>



int main(void){

int num_sundays = 0;
int days_in_month;
int days_passed = 2;
int i;
int month;

        for (i = 1901; i <= 2000; i++){
                for (month = 1; month <= 12; month++){
                        if (month == 4 || month == 6 || month == 9 || month == 11){
                                days_in_month = 30;

                        } else if (month == 2) {
                                if (i % 400 == 0 || (i % 4 == 0 && i % 100 != 0)){
                                        days_in_month = 29;
                                } else {
                                        days_in_month = 28;
                                }
                        } else {
                                days_in_month = 31;
                        }
                        if (days_passed % 7 == 0){
                                num_sundays++;
                        }

                   days_passed += days_in_month;
                }

        }

        printf("Number of Sundays is %d\n", num_sundays);
        return 0;
}
