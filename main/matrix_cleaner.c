#include "pathfinder.h"

static void clear_visit_arr_ex_finish(int finish_island) {
    for (int i = 0; i < in_data.num_of_islands; i++)
        for (int j = 0; j < in_data.num_of_islands; j++)
            if (j != finish_island)
                in_data.visit_matrix[i][j] = 0;
}

static void path_cheker_and_cleaner(int i, int temp_i, int finish_island) {
    for (int j = 0; j < in_data.num_of_islands; j++) {
        if (in_data.path_matrix[j][temp_i] == in_data.path_matrix[i][temp_i] && in_data.visit_matrix[j][temp_i] != 1)  {
            in_data.visit_matrix[in_data.route_arr[0]][finish_island] = 0;
            in_data.cleaner_flag[0] = 1;
            in_data.cleaner_flag[1] = i;
            in_data.cleaner_flag[2] = temp_i;
            break;
        }
    }
}

static void head_path_cleaner(void) {
    for (int i = 0; in_data.route_arr[i + 1] != -1; i++) {
        if (in_data.cleaner_flag[1] != in_data.route_arr[i+1] && in_data.cleaner_flag[2] != in_data.route_arr[i])
            in_data.visit_matrix[in_data.route_arr[i+1]][in_data.route_arr[i]] = 0;
            in_data.visit_matrix[in_data.route_arr[i]][in_data.route_arr[i+1]] = 0;
    }
}

void matrix_cleaner(int flag, int i, int temp_i, int finish_island) {
    switch (flag) {
        case(1): clear_visit_arr_ex_finish(finish_island); break;
        case(2): path_cheker_and_cleaner(i, temp_i, finish_island); break;
        case(3): head_path_cleaner();
    }
}
