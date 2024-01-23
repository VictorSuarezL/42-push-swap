#include <stdio.h>

// Function declarations
int get_target(t_list *stack_a, t_list *stack_b, int size_b);
int get_pos(t_list *lst, int target);

int get_target(t_list *stack_a, t_list *stack_b, int size_b)
{
	int target;
	t_list *tmp;

	if (stack_a->value < get_min(stack_b) || stack_a->value > get_max(stack_b))
	{
		target = get_max(stack_b);
	}
	return target;
}

int get_pos(t_list *lst, int target)
{
	int pos = 0;

	while (lst->value != target)
	{
		pos++;
		lst = lst->next;
	}
	return pos;
}


// Structure definition
typedef struct Node {
	int value;
	struct Node* next;
} t_list;

int main() {
	// Create a sample linked list
	t_list* stack_a = malloc(sizeof(t_list));
	stack_a->value = 5;
	stack_a->next = malloc(sizeof(t_list));
	stack_a->next->value = 10;
	stack_a->next->next = malloc(sizeof(t_list));
	stack_a->next->next->value = 15;
	stack_a->next->next->next = NULL;

	// Create another sample linked list
	t_list* stack_b = malloc(sizeof(t_list));
	stack_b->value = 20;
	stack_b->next = malloc(sizeof(t_list));
	stack_b->next->value = 25;
	stack_b->next->next = malloc(sizeof(t_list));
	stack_b->next->next->value = 30;
	stack_b->next->next->next = NULL;

	// Test the get_target function
	int target = get_target(stack_a, stack_b, 3);
	printf("Target: %d\n", target);

	// Test the get_pos function
	int pos = get_pos(stack_a, target);
	printf("Position: %d\n", pos);

	return 0;
}