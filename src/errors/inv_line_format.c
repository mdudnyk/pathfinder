#include "pathfinder.h"

static int mx_line_index(char *text, int start_index) {
    int index = start_index;

    while (text[index] != '\n') {
        if (text[index + 2] == '\0' && index == start_index)
            return -2;
        if (text[index + 2] == '\0')
            return -1;
        index++;
    }
    return ++index;
}

static bool line_format(char *string, int start_index) {
    int i = start_index;
    int temp = i;

    for ( ; string[i] != '-'; ++i)
        if (!mx_isletter(string[i]))
            return false;
    if (temp  == i++)
        return false;
    temp = i;
    for ( ; string[i] != ','; ++i)
        if (!mx_isletter(string[i]))
            return false;
    if (temp  == i++)
        return false;
    temp = i;
    if (string[i] == '0')
        return false;
    for ( ; string[i] != '\n'; ++i)
        if (!mx_isdigit(string[i]))
            return false;
    if (temp  == i)
        return false;
    return true;
}

static bool isl_dup_check(char *string, int start_index) {
    int i = start_index;
    int j = 0;
    char a[150];
    char b[150];
    
    for ( ; string[i] != '-'; j++, i++)
        a[j] = string[i];
    a[j] = '\0';
    for (j = 0, i++; string[i] != ','; j++, i++)
        b[j] = string[i];
    b[j] = '\0';
    if (!mx_strcmp(a, b))
        return false;           
    return true;
}

void inv_line_format(void) {
    int cur_index = 0;
    int line = 1;

    while (1) {
        cur_index = mx_line_index(in_data.string, cur_index);
        if (cur_index != -1) {
            line++;
            if (cur_index == - 2 || !line_format(in_data.string, cur_index) || !isl_dup_check(in_data.string, cur_index)) {
                char *line_str;
                mx_printerr("error: line ");
                mx_printerr(line_str = mx_itoa(line));
                mx_printerr(" is not valid\n");
                free(line_str);
                free(in_data.string);
                exit(1);
            }
        }
        else
            break;
    }
    in_data.num_of_bridges = line - 1;
}
