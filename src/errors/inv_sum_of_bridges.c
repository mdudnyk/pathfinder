#include "pathfinder.h"

static void print_error(void) {
        mx_printerr("error: sum of bridges lengths is too big\n");
        free(in_data.string);
        free(in_data.uniqe_islands);
        exit(1);
}

void inv_sum_of_bridges(void) {
    int i = 0;
    unsigned long sum = 0;
    bool flag = true;
    int atl;

    while (1) {
        for ( ; in_data.string[i] != ','; i++) 
            if (in_data.string[i] == '\0') {
                flag = false;
                break;
            }
        if (flag) {
            atl = my_atoull(&in_data.string[++i]);
            if (atl == -1)
                print_error();
            sum += atl;
            i++;
        }
        else 
            break;
    }
    if (sum > INT_MAX)
        print_error();
}
