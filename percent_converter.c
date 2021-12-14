#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
    Program: Percent converter
    Version: 0.2
*/

// ascii number increase
const int ascii_char_num = 48;

// return number from acsii char code
int int_from_char(int charachter) {
    return  charachter - ascii_char_num;
}

// checks the possibility of increasing the current number
int can_it_be_increased(uint64_t a, int b) {
    uint64_t until_max = ULLONG_MAX - a;
    if (b >= until_max) {
        return 0;
    }
    return 1;
}

// return user number input
uint64_t get_user_input() {
    int input = getchar();
    uint64_t result = 0;
    int char_counter = 1;

    while (input != '\n') {
        int number = int_from_char(input);
        if (!can_it_be_increased(result, number)) {
            return result;
        }
        if (char_counter > 1) {
            result *= 10;
        }
        result += number;
        input = getchar();
        char_counter++;
    }
    return result;
}

int main () {
    uint64_t first_num;
    printf("\nUINT_64_T MAX_SIZE: %llu\n", ULLONG_MAX);
    first_num = get_user_input();
    printf("\nRESULT :%llu\n", first_num);
    return 0;
}

