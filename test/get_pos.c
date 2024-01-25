#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

// Stack
typedef struct s_list
{
    int             index;
    int             value;
    int             steps_a;
    int             steps_b;
    int             total;
    struct s_list   *next;
}                   t_list;

// This function gives you the exact position in the list which value is equal to num
int get_pos(t_list *lst, int num)
{
    int pos = 0;

    while (lst->value != num)
    {
        pos++;
        lst = lst->next;
    }
    return pos;
}


void test_get_pos() {
    // Create a linked list
    t_list *node3 = (t_list*)malloc(sizeof(t_list));
    node3->value = 3;
    node3->next = NULL;

    t_list *node2 = (t_list*)malloc(sizeof(t_list));
    node2->value = 2;
    node2->next = node3;

    t_list *node1 = (t_list*)malloc(sizeof(t_list));
    node1->value = 1;
    node1->next = node2;

    // Test get_pos function
    assert(get_pos(node1, 1) == 0);
    assert(get_pos(node1, 2) == 1);
    assert(get_pos(node1, 3) == 2);

    // Free allocated memory
    free(node1);
    free(node2);
    free(node3);
}

int main() {
    test_get_pos();
    printf("All tests passed successfully.\n");
    return 0;
}






































