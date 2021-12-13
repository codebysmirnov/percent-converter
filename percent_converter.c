#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

/*
    Program: Percent converter
    Version: 0.1
*/

// ascii number increase
const int ascii_char_num = 48;

// return number from acsii char code
uint64_t int_from_char(int charachter) {
    return  charachter - ascii_char_num;
}

// return user number input
uint64_t get_user_input() {
    int input = getchar();
    uint64_t result = 0;
    int char_counter = 1;

    while (input != '\n') {
        if (char_counter > 1) {
            result *= 10;
        }
        result += int_from_char(input);
        input = getchar();
        char_counter++;
    }
    return result;
}

int main () {
    uint64_t first_num;
    first_num = get_user_input();
    printf("\nRESULT :%llu\n", first_num);
    return 0;
}

