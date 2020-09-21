#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Variables
    int h;

    do
    {
        h = get_int("Height: ");
        for (int i = 1; i <= h; i++)
        {
            for (int j = h; j > i; j--)
            {
                printf(" "); // adding spaces
            }
            for (int x = 0; x < i; x++)
            {
                printf("#"); // adding hashes
            }
            printf("  ");
            for (int z = 0; z < i; z++)
            {
                printf("#");
            }
            printf("\n");
        }
    }
    while (h < 1 || h > 8);
}