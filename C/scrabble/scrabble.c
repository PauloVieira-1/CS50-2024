#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int findindex(char letter);
int getscore(char *word);


char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int values[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int main(){

char *p_1 = get_string("Player 1: ");
char *p_2 = get_string("Player 2: ");

int score_1 = getscore(p_1);
int score_2 = getscore(p_2);


    if (score_1 > score_2) {
        printf("Player 1 wins!\n");
    } else if (score_2 > score_1) {
        printf("Player 2 wins!\n");
    } else {
        printf("It's a tie!\n");
    }

}

int findindex(char letter){

letter = toupper(letter);

for (int i = 0; i < 26; i++){
    if (letters[i] == letter){
        return i;
    }
}
return -1;
}

int getscore(char *word) {
    int score = 0;

    for (int x = 0; x < strlen(word); x++) {
        int index = findindex(word[x]);

        if (index != -1) {
            score += values[index];
        }
    }

    return score;
}
