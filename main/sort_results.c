#include "pathfinder.h"

static int int_arr_cmp(int *a, int *b) {
    for (int i = 0; a[i] != -1; i++) {
        if (a[i] > b[i]) {
           return 1;
        }
        if (a[i] < b[i]) {
           return 0;
        }
    }
    return 0;
}

void sort_results(void) {
    int *temp_route = NULL;
    int *temp_dist = NULL;

    for (int i = 0; in_data.route_list[i] != NULL; i++) {
        for (int j = i + 1; in_data.route_list[j] != NULL; j++) {
            if (int_arr_cmp(in_data.route_list[i], in_data.route_list[j])) {
                temp_route = in_data.route_list[i];
                in_data.route_list[i] = in_data.route_list[j];
                in_data.route_list[j] = temp_route;
                temp_dist = in_data.dist_list[i];
                in_data.dist_list[i] = in_data.dist_list[j];
                in_data.dist_list[j] = temp_dist;
            }
        }
    }
}
