#include "stringToInt.h"

int string_to_int(char* num, int length, int base) {
    int value = 0;
    for (int i = 0; i < length; i++){
        value *= base;
        value += (int) (num[i] - '0');
    }
    return value;
}
