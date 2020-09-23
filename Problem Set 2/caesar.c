#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prototypes
string round_ciphertext(int length, string plaintext, int k);
bool check_command_line_argument_is_digit(string cla); // To check command-line argument[1] (key) is digit

int main(int argc, string argv[])
{
    // Variables
    string plaintext;
    int length; // length of plaintext
    int rounded; // converting command-line argument[1] to integer
    string key;

    key = argv[1];
    if (argc == 2 && check_command_line_argument_is_digit(key))
    {
        plaintext = get_string("plaintext: ");
        length = strlen(plaintext);
        rounded = atoi(key);
        printf("ciphertext: %s\n", round_ciphertext(length, plaintext, rounded));
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

string round_ciphertext(int length, string plaintext, int k)
{
    // Variables
    int roundedLetter;

    k %= 26;
    for (int i = 0; i < length; i++)
    {
        roundedLetter = plaintext[i] + k;
        if (islower(plaintext[i]))
        {
            if (roundedLetter >= 'z') // if new char is greater than z
            {
                roundedLetter = (96 + k) - ('z' - plaintext[i]);
                plaintext[i] = roundedLetter;
            }
            else
            {
                plaintext[i] += k;
            }
        }
        else if (isupper(plaintext[i]))
        {
            if (roundedLetter >= 'Z') // if new char is greater than Z
            {
                roundedLetter = (64 + k) - ('Z' - plaintext[i]);
                plaintext[i] = roundedLetter;
            }
            else
            {
                plaintext[i] += k;
            }
        }
    }
    return plaintext;
}

bool check_command_line_argument_is_digit(string cla)
{
    // Variables
    bool isDigit = true;
    int length;

    length = strlen(cla);
    for (int i = 0; i < length; i++)
    {
        if (!isdigit((char) cla[i]))
        {
            isDigit = false;
        }
    }
    if (isDigit)
    {
        return true;
    }
    else
    {
        return false;
    }
}