#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


int index_result(int number_letters, int number_sent, int number_words);

int main(){

    char endings[] = {'.', '?', '!'};

    char *text = get_string("Text: ");
    char *token = strtok(text, " ");

    int num_letters = 0;
    int num_sent = 0;
    int num_words = 0;

    while (token != NULL){

        int word_len = strlen(token);

       // printf( "  %s\n", token );

        for (int x = 0; x < word_len; x++){
            char letter = token[x];

            if (isalpha(letter)){
                num_letters += 1;

            }

            for (int y = 0; y < 3; y++) {
                if (letter == endings[y]) {
                    num_sent += 1;
                }
            }

        }
        num_words += 1;
        token = strtok(NULL, " ");

    }

    // printf("%i, %i, %i", num_letters, num_sent, num_words);

    int result = index_result(num_letters, num_sent, num_words);

    if (result < 1){
        printf("Before Grade 1\n");
    }
    else if (result > 16){
        printf("Grade 16+\n");
    }
    else{
        printf("Grade %i\n", result);
    }

    return 0;
}


int index_result(int number_letters, int number_sent, int number_words) {
    float L = ((float) number_letters / number_words) * 100;
    float S = ((float) number_sent / number_words) * 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;

    int grade_level = round(index);

    return grade_level;
}

