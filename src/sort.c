#include <push_swap.h>
#include <stdio.h>

void count_steps_a(t_list *stack_a)
{
	int pos;
	int size_lst;

	size_lst = get_lst_size(stack_a);
	pos = 0;
	while(stack_a)
	{
		if (pos <= (size_lst/2))
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

void sort_three(t_list **lst)
{
	int min_pos;
	int max_pos;

	while (is_lst_ordered(*lst) == 0)
	{
		min_pos = get_pos(*lst, get_min(*lst));
		max_pos = get_pos(*lst, get_max(*lst));
		
		if (max_pos == 0 && min_pos == 2)
			ra(lst);
		else if (max_pos == 1 && min_pos == 0)
			sa(lst);
		else if (max_pos == 0 && min_pos == 1)
			ra(lst);
		else if (max_pos == 1 && min_pos == 2)
			rra(lst);
		else if (max_pos == 2 && min_pos == 1)
			sa(lst);
	}
}

int get_target(t_list *stack_a, t_list *stack_b, int size_b)
{
	int target;
	int last_value_b;
	int first_value_b;

	target = 0;
	if (stack_a->value < get_min(stack_b) || stack_a->value > get_max(stack_b))
		target = get_max(stack_b);
	else
	{
		first_value_b = get_node(stack_b, 0)->value;
		last_value_b = get_node(stack_b, size_b-1)->value;
		while(stack_b->next)
		{
			if (stack_a->value < stack_b->value && stack_a->value > stack_b->next->value)
			{
				target = stack_b->next->value;
			}
			else if (stack_a->value < last_value_b && stack_a->value > first_value_b)
			{
				target = first_value_b;
			}
			stack_b = stack_b->next;
		}
	}
	return target;
}

void count_steps_b(t_list *stack_a, t_list *stack_b)
{
	int size_b;
	int target;

	size_b = get_lst_size(stack_b);

	if(display == 1)
		printf("\n");
	while (stack_a)
	{
		target = get_target(stack_a, stack_b, size_b);
		if (get_pos(stack_b, target) <= size_b/2)
		{
			stack_a->steps_b = get_pos(stack_b, target);
		}
		else
		{
			stack_a->steps_b = -(size_b - get_pos(stack_b, target));
		}
		if(display == 1)
			printf("value_a = %i target = %i\n", stack_a->value, target);

		stack_a = stack_a->next;
	}
	if(display == 1)
		printf("\n");
}

int get_reverse_target(t_list *dst, t_list *src, int size_dst)
{
	int target;
	int src_value;
	int last_value_dst;
	int first_value_dst;

	src_value = src->value;
	if (src_value < get_min(dst) || src_value > get_max(dst))
		target = get_min(dst);
	else
	{
		first_value_dst = get_node(dst, 0)->value;
		last_value_dst = get_node(dst, size_dst-1)->value;

		while (dst->next)
		{
/* 			if (src_value > dst->value && src_value < dst->next->value)
			{
				target = dst->next->value;
			}
			else if (src_value < last_value_dst && src_value > first_value_dst)
			{
				target = last_value_dst;
			}
			else if (src_value > last_value_dst && src_value < first_value_dst)
			{
				target = first_value_dst;
			} */

			if (src_value > dst->value && src_value < dst->next->value)
			{
				target = dst->next->value;
			}
			// else if (src_value < last_value_dst && src_value > first_value_dst)
			// {
			// 	target = last_value_dst;
			// }
			else if (src_value > last_value_dst && src_value < first_value_dst)
			{
				target = first_value_dst;
			}
			
			dst = dst->next;
		}
	}
	

	return target;
}

void count_reverse_steps(t_list *dst, t_list *src)
{	
	int size_dst;
	int target;
	size_dst = get_lst_size(dst);
	if(display == 1)
		printf("\n");
	while (src)
	{
		target = get_reverse_target(dst, src, size_dst);
		if (get_pos(dst, target) <= size_dst/2)
		{
			src->steps_b = get_pos(dst, target);
		}
		else
		{
			// stack_a->steps_b = get_pos(stack_b, target) - size_b;
			src->steps_b = -(size_dst - get_pos(dst, target));
		}
		if(display == 1)
			printf("value_b = %i target = %i\n", src->value, target);

		src = src->next;
	}
	if(display == 1)
		printf("\n");	

}

void sum_steps(t_list *stack_a)
{
	while (stack_a)
	{	
		if((stack_a->steps_a < 0 && stack_a->steps_b < 0) || (stack_a->steps_a > 0 && stack_a->steps_b > 0))
		{		
			if (abs(stack_a->steps_a) > abs(stack_a->steps_b))
				stack_a->total = abs(stack_a->steps_a);
			else
				stack_a->total = abs(stack_a->steps_b);
		}
		else
			stack_a->total = abs(stack_a->steps_a) + abs(stack_a->steps_b);
		stack_a = stack_a->next;
	}
}

int get_cheapest(t_list *stack_a)
{
	int min;
	int value_min;

	if(stack_a)
	{
		min = stack_a->total;
		value_min = stack_a->value;
		// pos = get_pos(stack_a, stack_a->value);
		stack_a = stack_a->next;
	}

	// min_total = 123123;
	while(stack_a)
	{
		if(stack_a->total < min)
		{
			min = stack_a->total;
			// pos = get_pos(stack_a, stack_a->value);
			value_min = stack_a->value;
			// printf("here! ->>>> value = %i ->>>> min = %i\n", stack_a->value, min);
		}   
		stack_a = stack_a->next;
	}
	return value_min;
}

void sort(t_list **stack_a, t_list **stack_b, int pos)
{
	t_list *tmp;
	tmp = get_node(*stack_a, pos);

	while (tmp->steps_a != 0 || tmp->steps_b != 0)
	{
		if (tmp->steps_a < 0 && tmp->steps_b < 0)
		{
			rrr(stack_a, stack_b);
			tmp->steps_a++;
			tmp->steps_b++;
		}
		else if (tmp->steps_a > 0 && tmp->steps_b > 0)
		{
			rr(stack_a, stack_b);
			tmp->steps_a--;
			tmp->steps_b--;
		}
		else if (tmp->steps_a > 0)
		{
			ra(stack_a);
			tmp->steps_a--;
		}
		else if (tmp->steps_b > 0)
		{
			rb(stack_b);
			tmp->steps_b--;
		}
		else if (tmp->steps_a < 0)
		{
			rra(stack_a);
			tmp->steps_a++;
		}
		else if (tmp->steps_b < 0)
		{
			rrb(stack_b);
			tmp->steps_b++;
		}
	}
	pb(stack_a, stack_b);
}

void sort_reverse(t_list **stack_a, t_list **stack_b, int pos)
{
	t_list *tmp;
	// printf("pos = %i\n", pos);
	tmp = get_node(*stack_b, pos);
	// printf("\nwe're gonna move: %i\n", tmp->value);

	while (tmp->steps_a != 0 || tmp->steps_b != 0)
	{
		if (tmp->steps_a < 0 && tmp->steps_b < 0)
		{
			rrr(stack_a, stack_b);
			tmp->steps_a++;
			tmp->steps_b++;
		}
		else if (tmp->steps_a > 0 && tmp->steps_b > 0)
		{
			rr(stack_a, stack_b);
			tmp->steps_a--;
			tmp->steps_b--;
		}
		else if (tmp->steps_a > 0)
		{
			rb(stack_b);
			tmp->steps_a--;
		}
		else if (tmp->steps_b > 0)
		{
			ra(stack_a);
			tmp->steps_b--;
		}
		else if (tmp->steps_a < 0)
		{
			rrb(stack_b);
			tmp->steps_a++;
		}
		else if (tmp->steps_b < 0)
		{
			rra(stack_a);
			tmp->steps_b++;
		}
	}
	pa(stack_a, stack_b);
	// while (is_lst_ordered(*stack_a) == 0)
	// {
	// 	ra(stack_a);
	// }
}

void sort_a(t_list **stack_a, int pos)
{
	t_list *tmp;
	tmp = get_node(*stack_a, pos);

	while (tmp->steps_a != 0)
	{
		if (tmp->steps_a > 0)
		{
			ra(stack_a);
			tmp->steps_a--;
		}
		else if (tmp->steps_a < 0)
		{
			rra(stack_a);
			tmp->steps_a++;
		}
	}
}