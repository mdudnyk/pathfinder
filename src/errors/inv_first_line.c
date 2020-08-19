#include "pathfinder.h"

static void print_err(void) {
    mx_printerr("error: line 1 is not valid\n");
    free(in_data.string);
    exit(1);
}

void inv_first_line(void) {
    int i = 0;
    int number = my_atoull(in_data.string);

    if (!(mx_isdigit(in_data.string[i])) || number < 0)
        print_err();
    while (in_data.string[i] != '\n') {
        if (!(mx_isdigit(in_data.string[i])) || number < 0)    // only check if < 0 values and is digit
            print_err();
        i++;
    }
    in_data.num_of_islands = number;
}
