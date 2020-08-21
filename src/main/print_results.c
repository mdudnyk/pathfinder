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

static void print_route(int start_island, int finish_island, int i) {
    int len = 1;

    mx_printstr("Route: ");
    print_island_by_index(start_island);
    mx_printstr(" -> ");
    if (in_data.route_list[i][2] != -1) {
        for ( ; in_data.route_list[i][len + 1] != -1; len++) {  
                print_island_by_index(in_data.route_list[i][len]);
                mx_printstr(" -> ");
        }
    }
    print_island_by_index(finish_island);
    mx_printchar('\n');
}

static void print_dist(int start_island, int finish_island, int i) {
    int len = 0;

    mx_printstr("Distance: ");
    if (in_data.dist_list[i][1] != -1) {
        for ( ; in_data.dist_list[i][len] != -1; len++) {
            mx_printint(in_data.dist_list[i][len]);
            if (in_data.dist_list[i][len + 1] != -1) {     
                mx_printstr(" + ");
            }
            else
                mx_printstr(" = ");
        }
    }
    mx_printint(in_data.adj_matrix[in_data.num_of_islands][finish_island]);
    mx_printstr("\n========================================\n");
}

void print_results(int start, int finish) {
    for (int i = 0; in_data.route_list[i] != NULL; i++) {
        print_path(start, finish);
        print_route(start, finish, i);
        print_dist(start, finish, i);
    }
}
