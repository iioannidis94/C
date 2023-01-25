#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    // make the 26 lenth of string
    int freq[26] = {0};
    // error if the lines were dif than 2
    if (argc != 2)
    {
        printf("Enter only one command-line argument\n");
        return 1;
    }

    // loop and check the lower and upper letters in the string
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (islower(argv[1][i]))
        {
            freq[argv[1][i] - 'a']++;
        }

        else if (isupper(argv[1][i]))
        {
            freq[argv[1][i] - 'A']++;
        }
    }


    //
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        // If the key is invalid as by 1. not containing exact 26 characters,
        //   2. containing any non-alphabetic character,
        //   or  3. not containing each letter exactly once
        if (n != 26 || !isalpha(argv[1][i]) || freq[i] != 1)
        {
            printf("Invalid Key\n");
            return 1;
        }
    }
    string plaintext = get_string("plaintext:  ");

    printf("ciphertext: ");

    for (int i = 0, j = 0, n = strlen(plaintext); i < n; i++)
    {
        // Case is preserved by using tolower() & toupper() functions
        if (islower(plaintext[i]))
        {
            plaintext[i] = tolower(argv[1][plaintext[i] - 'a']);
        }
        else if (isupper(plaintext[i]))
        {
            plaintext[i] = toupper(argv[1][plaintext[i] - 'A']);
        }
        else
        {
            continue;
        }
    }

    printf("%s\n", plaintext);

    return 0;
}
