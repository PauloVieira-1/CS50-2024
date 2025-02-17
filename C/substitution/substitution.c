#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int findindex(char letter);
bool repeat_checker(string cyphercode);

char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(int argc, char *argv[]){


    if (argc != 2) {
        printf("Please input the cypher code as an argument.\n");
        return 1;
    }

    char *cypher_code = argv[1];

    if (strlen(cypher_code) != 26) {
        printf("Cypher code must be exactly 26 characters.\n");
        return 1;
    }

    bool repeat = repeat_checker(cypher_code);

    if (repeat){

        char * plaintext = get_string("plaintext: ");
        int text_length = strlen(plaintext);

        char cyphertext[text_length + 1];
        int new_index = 0;


    for (int x = 0; x < text_length; x++) {
        if (isalpha(plaintext[x])) {
            int index = findindex(plaintext[x]);
            char new_letter = cypher_code[index];

            if (islower(plaintext[x])) {
                cyphertext[new_index] = tolower(new_letter);
            } else {
                cyphertext[new_index] = toupper(new_letter);
            }
        } else {
            cyphertext[new_index] = plaintext[x];
        }
        new_index++;

    }
        cyphertext[new_index] = '\0';
        printf("ciphertext: %s\n", cyphertext);
        return 0;


    }
    else
    {
        printf("No character can be repeated");
        return 1;
    }


}

int findindex(char letter){

for (int i = 0; i < 26; i++){
    if (alphabet[i] == toupper(letter)){
        return i;
    }
}
return 1;
}


bool repeat_checker(string cyphercode)
{
   for (int i = 0, j = strlen(cyphercode); i < j; i++)
   {
      for (int k = i+1; k < j; k++)
      {
         if (cyphercode[i] == cyphercode[k])
         {
            return false;
         }

      }

      if (isalpha(cyphercode[i]) == false){
        return false;
      }
   }
   return true;
}

