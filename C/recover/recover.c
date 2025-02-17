#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
#define n 512

    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    };

    FILE *file = fopen(argv[1], "r");
    uint8_t buffer[n];
    int jpg_count = 0;
    char name[8];
    int jpg_found = 0;
    FILE *output;

    while (fread(buffer, 1, n, file) == n)
    {

        if ((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) &&
            ((buffer[3] & 0xf0) == 0xe0))
        {
            
            if (jpg_found == 1)
            {
                fclose(output);
            }
            else
            {
                jpg_found = 1;
            }

            sprintf(name, "%03i.jpg", jpg_count);

            output = fopen(name, "w");
            jpg_count++;
        }
        if (jpg_found == 1)
        {
            fwrite(&buffer, 512, 1, output);
        }
    }
    fclose(output);
    fclose(file);

    return 0;
};
