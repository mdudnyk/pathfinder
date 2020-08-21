#include "pathfinder.h"

void route_dist_holder_malloc(void) {
    in_data.route_list = malloc(sizeof(int*));
    in_data.dist_list = malloc(sizeof(int*));
    in_data.route_list[0] = NULL;
    in_data.dist_list[0] = NULL;
}

static int route_dist_holder_resizer(void) {
    int len = 0;
    int **temp_route = NULL;
    int **temp_dist = NULL;

    for ( ; in_data.route_list[len] != NULL; len++) {};
    temp_route = malloc((len + 2) * sizeof(int*));
    temp_dist = malloc((len + 2) * sizeof(int*));
    for (int i = 0; in_data.route_list[i] != NULL; i++) {
        temp_route[i] = in_data.route_list[i];
        temp_dist[i] = in_data.dist_list[i];
    }
    temp_route[len + 1] = NULL;
    temp_dist[len + 1] = NULL;
    free(in_data.route_list);
    free(in_data.dist_list);
    in_data.route_list = temp_route;
    in_data.dist_list = temp_dist;
    return len;
}

void route_dist_holder_arr_adder(void) {
    int size = 0;
    int len = 0;
    int *arr_route = NULL;
    int *arr_dist= NULL;
    size = route_dist_holder_resizer();
    for ( ; in_data.route_arr[len] != -1; len++) {};
    arr_route = malloc((len + 1) * sizeof(int));
    arr_dist = malloc((len + 1) * sizeof(int));
    for (int i = 0; i < len; i++) {
        arr_route[i] = in_data.route_arr[len - i - 1];
        arr_dist[i] = in_data.dist_arr[len - i - 2];
    }
    arr_route[len] = -1;
    arr_dist[len - 1] = -1;
    in_data.route_list[size] = arr_route;
    in_data.dist_list[size] = arr_dist;
}

void route_dist_holder_mem_free(void) {
    for (int i = 0; in_data.route_list[i] != NULL; i++) {
        free(in_data.route_list[i]);
        free(in_data.dist_list[i]);
    }
    free(in_data.route_list);
    free(in_data.dist_list);
}
