#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//analyse letters, words, sentences
void analyse_text(string text);

//compute grade
int compute_grade(int letters, int words, int sentences);


int main(void)
{
    // Get input words from people
    string text = get_string("Text: ");
    analyse_text(text);
}

// check the lenght and analyse the text
void analyse_text(string text)
{

    int grade = 0;
    int letters = 0;
    int words = 0;
    int sentences = 0;
//loop throuht the text
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char lower_char = tolower(text[i]);

        if ('a' <=  lower_char && lower_char <= 'z')
        {
            letters++;
        }
        else if (lower_char == ' ')
        {
            words++;
        }
        else if (lower_char == '.' || lower_char == '!' || lower_char == '?')
        {
            sentences++;
        }
    }
    words++;
// grade calculation
    grade = compute_grade(letters, words, sentences);

    if (0 < grade && grade < 16)
    {
        printf("Grade %i\n", grade);
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade 16+\n");
    }

}

// calculate grade: grade = 0.0588 * L - 0.296 * S - 15.8
int compute_grade(int letters, int words, int sentences)
{
    float L = 100.0000 * letters / words;
    float S = 100.0000 * sentences / words;

    float f =  0.0588 * L - 0.296 * S - 15.8;
    //printf("index: %f", f);
    return (int) round(f);
}