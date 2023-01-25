#include <cs50.h>
#include <stdio.h>

void blocks(int n);

int main(void)
{
    int height;
    //check the min and max height
    do
    {
        height = get_int("Height:");
    }
    while (height < 1 || height > 8);
    //call function
    blocks(height);
}

void blocks(int n)
{
    //loop for change lines
    for (int i = 0; i < n; i++)
    {
        //loop for spaces
        for (int k = n - i; k > 1; k--)
        {
            printf(" ");
        }
        //loop for bricks
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        //middle spaces
        printf("  ");
        //loop for next pyramid
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        printf("\n");
    }
}