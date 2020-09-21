// Libraries
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Variables
    long creditCardNumber = 0;
    long num = 0;
    int count = 0; // To count number of digit credit card
    int digits[16];
    int sumOfwerentMultiplyBy2 = 0;
    int sumOfMultiplyBy2 = 0;
    int total = 0; // When a digit multiply by 2 is higher than 10, it could be one digit
    int limit = 0;

    creditCardNumber = get_long("Number: "); // User input credit card number
    num = creditCardNumber;
    while (num > 0) // Counting number of digit
    {
        num /= 10;
        count++;
    }
    if (count >= 13 && count <= 16) // Number of digits credit card 13-16 inclusive
    {
        if (count == 16)
        {
            limit = 16;
        }
        else if (count == 15)
        {
            limit = 15;
        }
        else if (count == 14)
        {
            limit = 14;
        }
        else
        {
            limit = 13;
        }
        num = 0;
        for (int i = 0; i < limit; i++) // Assigning all digits as an element
        {
            digits[i] = (creditCardNumber % ((long)pow(10, limit) / (long)pow(10, num))) / ((long)pow(10, limit - 1) / (long)pow(10, num));
            num++;
        }
        for (int i = limit - 2; i >= 0; i = i - 2) // Calculating sum of multiply by 2, starting with the number’s second-to-last digit
        {
            total = digits[i] * 2; // multiply each of the underlined digits by 2
            if (total < 10)
            {
                sumOfMultiplyBy2 += total;
            }
            else
            {
                sumOfMultiplyBy2 += (total % 10);
                sumOfMultiplyBy2 += (total / 10);
            }
        }
        for (int i = limit - 1; i >= 0; i = i - 2) // Calculating sum of werent multiply by 2
        {
            sumOfwerentMultiplyBy2 += digits[i];
        }
        if ((sumOfMultiplyBy2 + sumOfwerentMultiplyBy2) % 10 == 0) // If the credit card valid, sum of the digits that weren’t multiplied by 2 (starting from the end)
        {
            if (count == 15 && digits[0] == 3 && (digits[1] == 4 || digits[1] == 7))
            {
                printf("AMEX\n");
            }
            else if (count == 16 && digits[0] == 5 && (digits[1] == 1 || digits[1] == 2 || digits[1] == 3 || digits[1] == 4 || digits[1] == 5))
            {
                printf("MASTERCARD\n");
            }
            else if (digits[0] == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}