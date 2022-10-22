#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "stringToInt.h"
#include "largeNumberRemainder.h"

#define ARR_SIZE 100001

typedef struct Test_data {
    unsigned short int base;
    unsigned short int modulus;
    unsigned short int remainder;
} Test_data;

typedef struct Part {
    // inclusive index
    unsigned int start;
    // exclusive index
    unsigned int end;
} Part;


int read_data(Test_data *tests, char* input_code){

    int chars_read;
    chars_read = scanf("%hu %hu %hu", &(tests->base), &(tests->modulus), &(tests->remainder));
    chars_read = scanf("%s", input_code);

    // remove
    if (chars_read > ARR_SIZE) {
        printf("fail");
    }

    return 0;
}

bool is_congruent (char *code, int length, int base, int mod, int remainder){
    return mod_num(code, length, base, mod) == remainder;
}

bool process_data(Test_data *tests, char* input_code) {
    Part parts[ARR_SIZE];
    unsigned int index = 0;
    Part cur_part;
    bool at_end = false;
    bool congruent = false;

    cur_part.start = 0;
    cur_part.end = 0;

    while (true) {
        cur_part.end += 1;
        
        if (input_code[cur_part.end] == '\0') {
            at_end = true;
        } else {
            at_end = false;
        }

        congruent = is_congruent(
                    input_code + cur_part.start,
                    cur_part.end - cur_part.start,
                    tests->base,
                    tests->modulus,
                    tests->remainder
                );

        if (congruent) {
            if (at_end) {
                return true;
            }

            if (input_code[cur_part.end] != '0') {
                parts[index].start = cur_part.start;
                parts[index].end = cur_part.end;
                cur_part.start = cur_part.end;
                cur_part.end = cur_part.start;
                index++;
            }
            
        } else if ( at_end ) {
            if (index == 0) return false;

            index--;
            cur_part.start = parts[index].start;
            cur_part.end = parts[index].end;
        }
    }
}


int main(){
    int characters_scanned;
    char input_code[ARR_SIZE];
    unsigned short int number_of_tests;
    Test_data test;

    characters_scanned = scanf("%hu", &number_of_tests);
    // remove
    if (characters_scanned > ARR_SIZE) {
        printf("fail");
    }

    for (int i=0; i<number_of_tests; i++){

        read_data(&test, input_code);
        input_code[ARR_SIZE-1] = '\0'; // Just making sure string is terminated
        if (process_data(&test, input_code)){
            printf("valid\n");
        } else {
            printf("invalid\n");
        }

    }
    return EXIT_SUCCESS;
}
