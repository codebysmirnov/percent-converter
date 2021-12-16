#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
    Program: Percent converter
    Version: 0.5
*/

// ascii number increase
const int ascii_char_num = 48;

// return number from acsii char code
int int_from_char(int charachter) {
    return  charachter - ascii_char_num;
}

// checks the possibility of increasing the current number
int can_it_be_increased(uint64_t a, int b) {
    uint64_t until_max = ULLONG_MAX - (a * 10);
    if (b >= until_max) {
        return 0;
    }
    return 1;
}

// error code: when added zero value or less ( <= 0)
const int err_num_too_small = -1;
// error code: when added max uint64 value (> ULLONG_MAX)
const int err_num_too_large = -2;
// error code: when pointer is null
const int err_null_pointer = -3;
// error code: when program has critical error and must be ended
const int err_crit = -4;


// return user number input from stdin
int std_input(/* OUT */ uint64_t *result) {
    if (result == NULL) {
        return err_null_pointer;
    }
    int input = getchar();
    int char_counter = 1;

    while (input != '\n') {
        int number = int_from_char(input);
        if (number <= 0 && (*result) == 0) {
            fflush(stdin); // free buffer for drop '\n' from current input
            return err_num_too_small;
        }
        if (!can_it_be_increased(*result, number)) {
            fflush(stdin); // free buffer for drop '\n' from current input
            (*result) = 0;
            return err_num_too_large;
        }
        if (char_counter > 1) {
            (*result) *= 10;
        }
        (*result) += number;
        input = getchar();
        char_counter++;
    }
    return 0;
}

// return number
int get_number(/* OUT */ uint64_t *number) {
    if (number == NULL) {
        return err_null_pointer;
    }
    int error = 0;
    uint64_t input = 0;
    error = std_input(&input);
    while (error < 0) {
        switch (error) {
        case err_num_too_small:
            printf("\nEntered number can't be a zero or less.\n");
            printf("\nPlease, enter number again on press enter for exit:\n");
            error = std_input(&input);
            break;
        case err_num_too_large:
            printf("\nMaximum allowed number is: %llu\n", ULLONG_MAX);
            printf("\nPlease, enter number again on press enter for exit:\n");
            error = std_input(&input);
            break;
        case err_null_pointer:
            return err_null_pointer;
        default:
            printf("UNDEFINED_ERROR_CODE: %d", error);
            break;
        }
    }
    *number = input;

    return error;
}

int main () {
    uint64_t number = 0;
    uint64_t percent = 0;
    int error = 0;
    printf("INT_MAX %llu\n", ULLONG_MAX);

    printf("\nEnter a number:\n");
    error = get_number(&number);
    if (error != 0) {
        printf("Program has critical error code: %d", error);
        return 1;
    }

    printf("\nEnter a percent:\n");
    error = get_number(&percent);
    if (error != 0) {
        printf("Program has critical error code: %d", error);
        return 1;
    }

    printf("\nNUMBER: %llu\n", number);
    printf("\nPERCENT: %llu\n", percent);

    return 0;
}

