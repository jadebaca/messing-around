/**
 * @file multiples.c
 *
 * @author Jade Baca
 *
 * @date 10/13/16
 *
 * Assignment: Lab 5
 *
 * @brief Calculates the sum of all the multiples of 3 or 5 below 1000
 *
 * @bugs not that I found
 *
 **/
#include <stdio.h>

int main(void)
{
        int sum_3 = 0;
        int sum_5 = 0;
        int sum_15 = 0;
        int i;
        int sum;


        for (i = 0; i < 1000; i++)
        {
                if (i % 3 == 0)
                {
                        sum_3 += i;
                }
                if (i % 5 == 0)
                {
                        sum_5 += i;
                }
                if (i % 15 == 0)
                {
                        sum_15 += i;
                }
        }
        sum = sum_3 + sum_5 - sum_15;
        printf("%d\n", sum);

        return 0;
}
