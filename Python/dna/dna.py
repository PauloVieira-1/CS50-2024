import csv
import sys


def main():

    # TODO: Check for command-line usage

    if len(sys.argv) > 1:
        database_csv = sys.argv[1]
        sequence = sys.argv[2]
    else:
        print("Argumnet 1 is the database, and argumnet 2 is the sequence.")


    # TODO: Read database file into a variable

    str_list = []
    rows = []
    with open(database_csv) as database:
        reader_data = csv.DictReader(database)

        header = reader_data.fieldnames
        for head in header[1:]:
            str_list.append(head)

        for row in reader_data:
            rows.append(row)

        # print(rows)


    # print(str_list)

    # TODO: Read DNA sequence file into a variable

    line = ""
    with open(sequence) as seq:
        for row in seq:
            for letter in row:
                line += letter
    # print(line)


    # TODO: Find longest match of each STR in DNA sequence

    str_dict = {}
    for STR in str_list:
        longest = longest_match(line, STR)
        if STR not in str_dict:
            str_dict[STR] = longest

    # print(str_dict)


    # TODO: Check database for matching profiles

    found = False

    for row in rows:
        match = True
        for key, value in str_dict.items():
            if row.get(key) != str(value):
                match = False
                break
        if match:
            print(row['name'])
            found = True
            break

    if found != True:
        print("No Match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
