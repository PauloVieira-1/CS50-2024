#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {

        height = get_int("Height: ");

        }
        while (height <= 0);


        for (int i = height - 1; i >= 0; i--)
        {

            for (int j = 0; j < i; j++)
            {
                printf(" ");

            }

            for (int f = 0; (f + i) < height; f++)
            {
                printf("#");

            }

            printf("  ");


            for (int f = 0; (f + i) < height; f++)
            {
                printf("#");

            }

            printf("\n");

        }


}
