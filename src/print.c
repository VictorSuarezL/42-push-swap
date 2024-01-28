#include <push_swap.h>
#include <stdio.h>

void print_double_p(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
}

void print_array_of_int(int *num, int len)
{
	int i = 0;

	while(i < len)
	{
		printf(" %i,", num[i]);
		i++;
	}
	printf("\n");
}

void print_list(t_list *lst)
{
	while(lst)
	{
		printf("%i\n", lst->value);
		lst = lst->next;
	}
}

void display_lst(t_list *stack_a, t_list *stack_b)
{
	// int cheapest;
	// int pos;

	if (stack_a == NULL && stack_b == NULL)
		return;
	// cheapest = get_cheapest(stack_a);
	// pos = get_pos(stack_a, cheapest);
	// taget
	printf("stack_a\t\t\t\tstack_b\n");

	while (stack_a != NULL || stack_b != NULL)
	{
		if (stack_a != NULL)
		{
			printf("%d | %d | %d | %d\t\t\t", stack_a->value, stack_a->steps_a, stack_a->steps_b, stack_a->total);
			stack_a = stack_a->next;
		}
		else
		{
			printf("\t\t\t\t");
		}

		if (stack_b != NULL)
		{
			printf("%i", stack_b->value);
			stack_b = stack_b->next;
		}

		printf("\n");
	}
	printf("\t\t\t<------>\n");
}

void display_lst_reverse(t_list *stack_a, t_list *stack_b)
{
	if (stack_a == NULL && stack_b == NULL)
		return;

	printf("stack_a\t\t\t\tstack_b\n");

	while (stack_a != NULL || stack_b != NULL)
	{
		if (stack_a != NULL)
		{
			printf("%i\t\t\t\t", stack_a->value);
			stack_a = stack_a->next;
		}
		else
			printf("\t\t\t\t");

		if (stack_b != NULL)
		{
			printf("%d | %d | %d | %d\t\t\t", stack_b->value, stack_b->steps_a, stack_b->steps_b, stack_b->total);
			stack_b = stack_b->next;

		}

		printf("\n");
	}
	printf("\t\t\t<------>\n");
}
