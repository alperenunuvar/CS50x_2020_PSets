// Libraries
#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Variables
    float dollars; // input
    int cents; // converted dollars to cents
    int numberOfCoins = 0;
    int coins[] = {25, 10, 5, 1};
    int i = 0;
    
    do
    {
        dollars = get_float("Change owed: ");
        cents = round(dollars * 100); // converting
        
        while (cents > 0)
        {
            if (cents >= coins[i])
            {
                cents -= coins[i];
                numberOfCoins++;
            }
            else
            {
                i++;
            }
        }
        printf("%i\n", numberOfCoins);
    }
    while (dollars <= 0); // ask until greater than 0
}