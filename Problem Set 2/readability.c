// Libraries
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Prototypes
int count_letters(string text, int length);
int count_words(string text, int length);
int count_sentences(string text, int length);
int calculate_readability(int numberOfLetters, int numberOfWords, int numberOfSentences);

int main(void)
{
    // Variables
    string text;
    int length; // length of text
    int numberOfLetters;
    int numberOfWords;
    int numberOfSentences;
    int index; // rounded result of Coleman-Liau algorithm

    text = get_string("Text: "); // input user
    length = strlen(text);
    numberOfLetters = count_letters(text, length);
    numberOfWords = count_words(text, length);
    numberOfSentences = count_sentences(text, length);
    index = calculate_readability(numberOfLetters, numberOfWords, numberOfSentences);

    //printf("\n%i letter(s)\n%i word(s)\n%i sentence(s)\n", numberOfLetters, numberOfWords, numberOfSentences);
    //printf("Index: %i\n", index);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text, int length)
{
    // Variables
    int numberOfLetters = 0;

    for (int i = 0; i < length; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            numberOfLetters++;
        }
    }
    return numberOfLetters;
}

int count_words(string text, int length)
{
    // Variables
    int numberOfWords = 1;

    for (int i = 0; i < length; i++)
    {
        if (text[i] == ' ')
        {
            numberOfWords++;
        }
    }
    return numberOfWords;
}

int count_sentences(string text, int length)
{
    // Variables
    int numberOfSentences = 0;

    for (int i = 0; i < length; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            numberOfSentences++;
        }
    }
    return numberOfSentences;
}

int calculate_readability(int numberOfLetters, int numberOfWords, int numberOfSentences)
{
    return round(0.0588 * numberOfLetters / numberOfWords * 100 - 0.296 * numberOfSentences / numberOfWords * 100 - 15.8);
}