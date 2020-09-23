// Libraries
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Prototypes
bool check_command_line_argument_is_ok(string key);
string make_substitution(string plaintext, string key);

int main(int argc, string argv[])
{
    // Variables
    string plaintext;

    if (argc == 2)
    {
        if (strlen(argv[1]) == 26)
        {
            if (check_command_line_argument_is_ok(argv[1]))
            {
                plaintext = get_string("plaintext: ");
                printf("ciphertext: %s\n", make_substitution(plaintext, argv[1]));
                return 0;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

bool check_command_line_argument_is_ok(string key)
{
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if ((key[i] == key[j]) || (!isalpha(key[j]))) // Check chars used only once or only alphabetical
            {
                printf("Key must contain only alphabetic character, or not containing each letter exactly once.\n");
                return false;
            }
        }
    }
    return true;
}

string make_substitution(string plaintext, string key)
{
    // Variables
    int length;
    char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    length = strlen(plaintext);
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            if (plaintext[i] == alphabet[j]) // To locate place of alphabet
            {
                if (isupper(plaintext[i])) // If plaintext letter is upper-case
                {
                    plaintext[i] = toupper(key[j % 26]); // j%26 because all upper and lower case letters in one array
                    break;
                }
                else // If plaintext letter is lower-case
                {
                    plaintext[i] = tolower(key[j]);
                    break;
                }
            }
        }
    }
    return plaintext;
}