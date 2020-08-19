#ifndef PATHFINDER_H
#define PATHFINDER_H

#include "libmx.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>

struct input_data {
    char *string;
    int file_len;
    int num_of_islands;
    int num_of_bridges;
    char *uniqe_islands;
    int **adj_matrix;
    int **path_matrix;
    int **visit_matrix;
    int *route_arr;
    int *dist_arr;
    int begin_index;
    int *cleaner_flag;
}      in_data;

void error_handling(int argc, char *filename);
void inv_argc(int argc);
void inv_no_file(char *filename);
void inv_empty_file(char *filename);
void inv_first_line(void);
int my_atoull(const char *str);
void inv_line_format(void);
void inv_num_of_islands(void);
void inv_dup_bridges(void);
void inv_sum_of_bridges(void);

void adjacency_matrix_init(void);
void path_matrix_init(void);
void dajkstra(void);
void create_visit_route_dist_matrixes(void);
void route_dist_creating(int start_island);
void matrix_cleaner(int flag, int i, int temp_i, int finish_island);
void init_help_arr(int flag);
void print_result(int start, int finish);

#endif
