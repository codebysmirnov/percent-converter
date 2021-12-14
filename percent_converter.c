#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
    Program: Percent converter
    Version: 0.3
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

// return user number input
int get_user_num_input(uint64_t *result) {
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

int main () {
    uint64_t first_num = 0;
    printf("\nUINT_64_T_MAX_SIZE: %llu\n", ULLONG_MAX);

    int error = 0;
    error = get_user_num_input(&first_num);
    while (error < 0) {
        switch (error) {
        case err_num_too_small:
            printf("\nEntered number can't be a zero or less.\n");
            printf("\nPlease, enter number again on press enter for exit:\n");
            error = get_user_num_input(&first_num);
            break;
        case err_num_too_large:
            printf("\nMaximum allowed number is: %llu\n", ULLONG_MAX);
            printf("\nPlease, enter number again on press enter for exit:\n");
            error = get_user_num_input(&first_num);
            break;
        default:
            printf("UNDEFINED_ERROR_CODE: %d", error);
            break;
        }
    }

    printf("\nRESULT: %llu\n", first_num);

    return 0;
}

