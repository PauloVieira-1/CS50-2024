#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int step_1(string number, int length);
int step_2(string number, int length);

int main(void)
{
    string number_s = get_string("Number: ");
    int number_length = strlen(number_s);

    int multiplied_sum_1 = step_1(number_s, number_length);
    int multiplied_sum_2 = step_2(number_s, number_length);
    int total_sum_check = (multiplied_sum_1 + multiplied_sum_2) % 10;

    if (total_sum_check == 0) {
        if (((number_s[0] == '3' && number_s[1] == '4') || (number_s[0] == '3' && number_s[1] == '7')) && (number_length == 15)) {
            printf("AMEX\n");
        }
        else if ((number_length == 16) &&
                   ((number_s[0] == '5' && number_s[1] == '1') ||
                    (number_s[0] == '5' && number_s[1] == '2') ||
                    (number_s[0] == '5' && number_s[1] == '3') ||
                    (number_s[0] == '5' && number_s[1] == '4') ||
                    (number_s[0] == '5' && number_s[1] == '5'))) {
            printf("MASTERCARD\n");
        }
        else if ((number_s[0] == '4') &&
                   (number_length == 13 || number_length == 16 || number_length == 19)) {
            printf("VISA\n");
        }
        else {
            printf("INVALID\n");
        }
    }
    else {
        printf("INVALID\n");
    }

    return 0;
}

int step_1(string number, int length){
    int sum = 0;
    for (int i = length - 2; i >= 0; i -= 2)
    {
        int product = 2 * (number[i] - 48);
        sum += (product / 10) + (product % 10);
    }
    return sum;
}

int step_2(string number, int length){
    int sum = 0;
    for (int i = length - 1; i >= 0; i -= 2) {
        sum += number[i] - 48;
    }
    return sum;
}
