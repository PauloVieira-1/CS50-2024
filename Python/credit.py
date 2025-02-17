

number_string = input("Number: ")
number_length = len(number_string)

def step_1(number_string, length):
    total = 0

    for i in reversed(range(length - 2, -1, -2)):
        product = 2 * int(number_string[i])
        product_string = str(product)

        for z in product_string:
            total += int(z)

    return total

def step_2(number_string, length):
    total = 0;

    for j in reversed(range(length - 1, -1, -2)):
        total += int(number_string[j])

    return total


def check_credit_card(number_s, sum_1, sum_2):

    total_sum_check = (sum_1 + sum_2) % 10

    if total_sum_check == 0:
        if ((number_s[0] == '3' and number_s[1] == '4') or (number_s[0] == '3' and number_s[1] == '7')) and (number_length == 15):
            print("AMEX")
        elif (number_length == 16) and (
                (number_s[0] == '5' and number_s[1] == '1') or
                (number_s[0] == '5' and number_s[1] == '2') or
                (number_s[0] == '5' and number_s[1] == '3') or
                (number_s[0] == '5' and number_s[1] == '4') or
                (number_s[0] == '5' and number_s[1] == '5')):
            print("MASTERCARD")
        elif number_s[0] == '4' and (number_length == 13 or number_length == 16 or number_length == 19):
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")



multiplied_sum_1 = step_1(number_string, number_length)
multiplied_sum_2 = step_2(number_string, number_length)

print(check_credit_card(number_string, multiplied_sum_1, multiplied_sum_2))




