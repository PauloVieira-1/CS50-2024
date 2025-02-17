#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int scaler(int argc, char *argv[]){

    FILE *input = fopen(argv[1], "r");
    FILE *output = fopen(argv[2], "w");

    float factor = atof(argv[3]);
    const int HEADER_SIZE = 44 * sizeof(char);

    if ((input == NULL) || (output == NULL))
    {
        printf("Could not open file.\n");
        return 1;

    }
    else
    {

        uint8_t header[HEADER_SIZE];

        fread(header, HEADER_SIZE, 1, input);
        fwrite(header, HEADER_SIZE, 1, output);

        int16_t buffer;

        while ((fread(&buffer,sizeof(int16_t), 1, input)) != 0){

            buffer *= factor;
            fwrite(&buffer, sizeof(int16_t), 1, output);

        };

    }

    fclose(input);
    fclose(output);

    return 0;

};

int main(int argc, char* argv[])
{

        if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    };


    return scaler(argc, argv);
}
