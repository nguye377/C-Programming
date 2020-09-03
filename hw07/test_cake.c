#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include "clog.h"  // optional
#include "cake.h"
#include "miniunit.h"

int _test_cake() {
    mu_start();

    //------------------------------------------
    // Create a list of size 3.
    struct Node* list = create_list("Al", "Bo", "Cy", NULL);

    // Check the contents of the list against an array.
    mu_check(is_names(list, 3, (const char*[]) {"Al", "Bo", "Cy"}));

    // Detach the second node and free it.
    struct Node* bo_node = detach_next_node(&list);
    destroy_list(&bo_node);
    mu_check(bo_node == NULL);

    // Verify that the node is no longer in the list.
    mu_check(!has_name(list, "Bo"));

    // Verify that the list contains everything except the detached node.
    mu_check(is_names(list, 2, (const char*[]) {"Al", "Cy"}));

    // Destroy list so we can start over.
    destroy_list(&list);
    mu_check(list == NULL);

    // Create the same list again.
    struct Node* list = create_list("Al", "Bo", "Cy", NULL);

    // Choose winner.
    choose_winner(&list, 3);
    mu_check(strcmp(list -> name, "Bo") == 0);
    destroy_list(&list);
    mu_check(list == NULL);

    //------------------------------------------
    mu_end();

    
}

// int _test_is_names() {
//     mu_start();
//     struct Node* start_node = create_list("Al", "Bo", "Cy", NULL);
//     mu_check(is_names(start_node, 3, (const char*[]) {"Al", "Bo", "Cy"}) == true);
//     destroy_list(&start_node);
//     mu_end();

//     return 0;
// }

int main(int argc, char ** argv) {
    struct Node * start = create_list("Alice", "Binh", "Haobo", "Gore", NULL);
    
    // print_list(start);
    choose_winner(&start, 1);
    //count_nodes(start);
    destroy_list(&start);
    //print_list(temp);
    //print_list(temp);
    mu_run(_test_cake);
    //mu_run(_test_is_names);

    return EXIT_SUCCESS;
}