#include "pathfinder.h"

static void mx_sort_islands_in_line(char *first, char *second, int line_index, char *string) {
    int i = line_index;

    for (int j = 0; first[j] != '\0'; i++, j++)
        string[i] = first[j];
    string[i++] = '-';
    for (int j = 0; second[j] != '\0'; i++, j++)
        string[i] = second[j];
}

static void isl_order_check(char *string) {
    int i = 0;
    int j = 0;
    char a[150];
    char b[150];
    int temp = 0;
    
    for (int z = 0; z < in_data.num_of_bridges; z++) {
        for (j = 0 ; string[i] != '-'; j++, i++)
            a[j] = string[i];
        a[j] = '\0';
        for (j = 0, i++; string[i] != ','; j++, i++)
            b[j] = string[i];
        b[j] = '\0';
        if (mx_strcmp(a, b) > 0) 
            mx_sort_islands_in_line(b, a, temp, string);      // sort islands in ascetic order in a line
        while (string[++i] != '\n') {};
        temp = ++i;
    }          
}

static char *mx_dup_from_second_line(char *src) {
    int i = 0;
    int len_src = mx_strlen(src);

    while (src[i] != '\n') 
        i++;
    i++; 
    char *dst = mx_strnew(len_src - i);
    for (int j = 0; j < len_src - i; j++)
        dst[j] = src[j + i];
    return dst;
}

void print_error(char *temp_str) {
    mx_printerr("error: duplicate bridges\n");
    free(in_data.string);
    free(in_data.uniqe_islands);
    free(temp_str);
    exit(1);
}

void inv_dup_bridges(void) {
    char *temp_str = mx_dup_from_second_line(in_data.string);
    int z = 0;
    int  line_index = 0;

    isl_order_check(temp_str);
    for (int i = 0; temp_str[i] != '\0'; i++)
        if (temp_str[i] == ',')
            temp_str[i] = '\0';
    for (int i = 0; i < in_data.num_of_bridges - 1; i++) {
        for (int j = i; j < in_data.num_of_bridges - 1; j++) {
            for ( ; temp_str[z] != '\n'; z++) {};
            if ((mx_strcmp(&temp_str[line_index], &temp_str[++z])) == 0)
                print_error(temp_str);
        }
        while (temp_str[line_index++] != '\n') {};
        z = line_index;
    }  
    free(temp_str);
}
