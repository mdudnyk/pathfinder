#include "pathfinder.h"

static void print_island_by_index(int index) {
    int i = 0;

    for (int j = 0 ; j < index; j++) {
        while (in_data.uniqe_islands[++i] != ' ');
        i++;
    }
    while (mx_isletter(in_data.uniqe_islands[i])) {
        mx_printchar(in_data.uniqe_islands[i]);
        i++;
    }
}

static void print_path(int start_island, int finish_island) {
    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    print_island_by_index(start_island);
    mx_printstr(" -> ");
    print_island_by_index(finish_island);
    mx_printchar('\n');
}

static void print_route(int start_island, int finish_island) {
    int len = 0;

    mx_printstr("Route: ");
    print_island_by_index(start_island);
    mx_printstr(" -> ");
    if (in_data.route_arr[1] != -1) {
        for ( ; in_data.route_arr[len] != -1; len++) {};
        for (int i = len - 2; i >= 0; i--) {
                print_island_by_index(in_data.route_arr[i]);
                mx_printstr(" -> ");
        }
    }
    print_island_by_index(finish_island);
    mx_printchar('\n');
}

static void print_dist(int start_island, int finish_island) {
    int len = 0;

    mx_printstr("Distance: ");
    if (in_data.dist_arr[1] != -1) {
        for ( ; in_data.dist_arr[len] != -1; len++) {};
        for (int i = len - 1; i >= 0; i--) {
            mx_printint(in_data.dist_arr[i]);
            if (i != 0) {  
                mx_printstr(" + ");
            }
            else
                mx_printstr(" = ");
        }
    }
    mx_printint(in_data.adj_matrix[in_data.num_of_islands][finish_island]);
    mx_printchar('\n');
    mx_printstr("========================================\n");
}

void print_result(int start, int finish) {
    print_path(start, finish);
    print_route(start, finish);
    print_dist(start, finish);
}
