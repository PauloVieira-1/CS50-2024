


while True:
    height = input("Height: ")

    try:
        number_height = int(height) + 1
        if number_height > 1 and number_height < 10:
            break
    except:
        print("Height must be an integer greater than 0")


if number_height >= 0:
    for i in reversed(range(0,number_height - 1)):

        # print(f"x_{i}")

        for j in range(i):
            print(" ", end="")

        z = 0
        while (z + i) < number_height - 1:
            print("#", end="")
            z += 1

        print("  ", end="")

        w = 0
        while (w + i) < number_height - 1:
            print("#", end="")
            w += 1

        i = i - 1
        print("")

