/**
 * @file difference.c
 *
 * @author Jade Baca
 *
 * @date 3/23/17
 *
 * Assignment: Lab 5
 *
 * @brief Calculates the sum of all the multiples of 3 or 5 below 1000
 *
 * @bugs not that I found
 *
 **/
#include <stdio.h>

#define SIZE 100

int main(void)
{
        int a[SIZE];
        int i;
        int sum = 0;
        int tmp = 0;
        int square;
        int diff;

        for(i = 0; i < SIZE; i++){
                a[i] = i + 1;
        }

        for(i = 0; i < SIZE; i++){
                sum += a[i] * a[i];
        }

        for(i = 0; i < SIZE; i++){
                tmp += a[i];
        }

        square = tmp * tmp;
        diff = square - sum;

        printf("%d\n", diff);
}
