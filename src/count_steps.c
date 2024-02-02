#include <push_swap.h>

void	count_steps_a(t_list *stack_a)
{
	int	pos;
	int	size_lst;

	size_lst = get_lst_size(stack_a);
	pos = 0;
	while (stack_a)
	{
		if (pos <= (size_lst / 2))
		{
			stack_a->steps_a = pos;
		}
		else
		{
			stack_a->steps_a = pos - size_lst;
		}
		stack_a = stack_a->next;
		pos++;
	}
}

int	get_target(t_list *stack_a, t_list *stack_b, int size_b)
{
	int	target;
	int	last_value_b;
	int	first_value_b;

	target = 0;
	if (stack_a->value < get_min(stack_b) || stack_a->value > get_max(stack_b))
		target = get_max(stack_b);
	else
	{
		first_value_b = get_node(stack_b, 0)->value;
		last_value_b = get_node(stack_b, size_b - 1)->value;
		while (stack_b->next)
		{
			if (stack_a->value < stack_b->value
				&& stack_a->value > stack_b->next->value)
				target = stack_b->next->value;
			else if (stack_a->value < last_value_b
				&& stack_a->value > first_value_b)
				target = first_value_b;
			stack_b = stack_b->next;
		}
	}
	return (target);
}

void	count_steps_b(t_list *stack_a, t_list *stack_b)
{
	int	size_b;
	int	target;

	size_b = get_lst_size(stack_b);
	while (stack_a)
	{
		target = get_target(stack_a, stack_b, size_b);
		if (get_pos(stack_b, target) <= size_b / 2)
		{
			stack_a->steps_b = get_pos(stack_b, target);
		}
		else
		{
			stack_a->steps_b = -(size_b - get_pos(stack_b, target));
		}
		stack_a = stack_a->next;
	}
}
