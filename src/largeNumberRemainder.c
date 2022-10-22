#include "largeNumberRemainder.h"
#include "stringToInt.h"

int pow_int(int x, int y) {
    int value = 1;
    for (int i=0; i < y; i++) value *= x;
    return value;
}

int mod_num(char* num, int length, int base, int mod){
    int CHUNK = 5;
    int section_size;
    char* pointer = num;
    int remainder = 0;
    int base_mod = 1;
    int base_rem = pow_int(base, CHUNK) % mod;
    int section_reminder = 0;

    if (length < CHUNK) {
        return string_to_int(num, length, base) % mod;
    }

    pointer += length - CHUNK;
    while (1) {
        section_reminder = string_to_int(pointer, CHUNK, base) % mod;
        section_reminder *= base_mod;
        remainder += section_reminder;
        remainder = remainder % mod;
        base_mod *= base_rem;
        base_mod = base_mod % mod;
        pointer -= CHUNK;
        if (pointer < num) {
            section_size = CHUNK - (num - pointer);
            pointer = num;
            if (section_size == 0) {
                break;
            }
            section_reminder = string_to_int(pointer, section_size, base) % mod;
            section_reminder *= base_mod;
            remainder += section_reminder;
            remainder = remainder % mod;
            break;
        }
    }

    return remainder;
}
