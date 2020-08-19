#include "pathfinder.h"

void error_handling(int argc, char *filename) {
    inv_argc(argc);
    inv_no_file(filename);
    inv_empty_file(filename);

    in_data.string = mx_file_to_str(filename);   // read file and set pointer to string in struct in_data

    inv_first_line();
    inv_line_format();
    inv_num_of_islands();
    inv_dup_bridges();
    inv_sum_of_bridges();
}
