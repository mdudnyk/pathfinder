#include "pathfinder.h"

void inv_no_file(char *filename) {
    if (mx_file_len(filename) == -1) {
        mx_printerr("error: file ");
        mx_printerr(filename);
        mx_printerr(" does not exist\n");
        exit(1);
    }
}
