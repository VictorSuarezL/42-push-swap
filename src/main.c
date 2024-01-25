/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:06:25 by vsanz-su          #+#    #+#             */
/*   Updated: 2024/01/19 16:52:13 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

static void	leaks(void)
{
	system("leaks push_swap");
}

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

int get_min(t_list *lst)
{
	int min;

	if(lst)
	{
		min = lst->value;
		lst = lst->next;
	}

	while(lst)
	{
		if(lst->value < min)
			min = lst->value;
		lst = lst->next;
	}
	return min;
}

int get_max(t_list *lst)
{
	int max;

	if(lst)
	{
		max = lst->value;
		lst = lst->next;
	}

	while(lst)
	{
		if(lst->value > max)
			max = lst->value;
		lst = lst->next;
	}
	return max;
}

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
		else if (min_pos == 1 && max_pos == 2)
			sa(lst);
		
		// print_list(*lst);
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
			// stack_a->steps_b = get_pos(stack_b, target) - size_b;
			stack_a->steps_b = -(size_b - get_pos(stack_b, target));
		}
		printf("value_a = %i target = %i steps_b = %i\n", stack_a->value, target, stack_a->steps_b);

		stack_a = stack_a->next;
	}
	printf("\n");
}

int get_reverse_target(t_list *dst, t_list *src, int size_dst)
{
	int target;
	int last_value_dst;
	int first_value_dst;

	if (src->value < get_min(dst)) //|| stack_a->value > get_max(stack_b))
		target = get_min(dst);

	first_value_dst = get_node(dst, 0)->value;
	last_value_dst = get_node(dst, size_dst-1)->value;

	while (dst->next)
	{
		if (src->value > dst->value && src->value < dst->next->value)
		{
			target = dst->next->value;
		}
		else if (src->value < last_value_dst && src->value > first_value_dst)
		{
			target = last_value_dst;
		}
		else if (src->value > last_value_dst && src->value < first_value_dst)
		{
			target = first_value_dst;
		}
		
		dst = dst->next;
	}
	return target;
}

void count_reverse_steps(t_list *dst, t_list *src)
{	
	int size_dst;
	int target;
	size_dst = get_lst_size(dst);
	// while (src)
	// {
	// 	printf("value_b = %i target = %i\n", src->value, get_reverse_target(dst, src, size_dst));
	// 	src = src->next;
	// }
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
		printf("value_b = %i target = %i steps_b = %i\n", src->value, target, src->steps_b);

		src = src->next;
	}
	printf("\n");	

}

void sum_steps(t_list *stack_a)
{
	// while (stack_a)
	// {
	// 	stack_a->total = abs(stack_a->steps_a) + abs(stack_a->steps_b);
	// 	stack_a = stack_a->next;
	// }

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
/* 	int pos;
	int min_total;

	t_list *tmp;

	pos = -1;
	if(stack_a)
	{
		min_total = stack_a->total;
		pos = get_pos(stack_a, stack_a->value);
		stack_a = stack_a->next;
	}

	min_total = 123123;
	while(stack_a)
	{
		if(stack_a->total < min_total)
		{
			min_total = stack_a->total;
			// pos = get_pos(stack_a, stack_a->value);
			printf("here! ->>>> value = %i ->>>> pos = %i\n", stack_a->value, get_pos(stack_a, stack_a->value));
		}   
		stack_a = stack_a->next;
	}
	return pos; */

	// int pos;
	int min;
	int value_min;

	// t_list *tmp;

	// pos = -1;
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
	// printf("pos = %i\n", pos);
	tmp = get_node(*stack_a, pos);
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
}

int	main(int ac, char *av[])
{
	if (ac < 1)
		return (-1);


	t_list **stack_a;
	t_list **stack_b;

	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));

	*stack_a = NULL;
	*stack_b = NULL;

	ft_init_stack(stack_a, ac, av);
	if(is_lst_ordered(*stack_a))
	{
		printf("Ordered!\n");
	}
	else
	{
		// print_list(*stack_a);
		// sort_three(stack_a);
		int pos;
		int i = 0;
		int cheapest;

		pb(stack_a, stack_b);
		pb(stack_a, stack_b);

/* 		rb(stack_b);
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		rb(stack_b);
		rb(stack_b);
		pb(stack_a, stack_b);
		// rra(stack_a);
		// rrb(stack_b);
		rrr(stack_a, stack_b);
		rr(stack_a, stack_b);

		// pb(stack_a, stack_b);

		display_lst(*stack_a, *stack_b); */



		while (get_lst_size(*stack_a) > 3)
		{
			count_steps_a(*stack_a);
			count_steps_b(*stack_a, *stack_b);
			sum_steps(*stack_a);
			display_lst(*stack_a, *stack_b);
			cheapest = get_cheapest(*stack_a);
			pos = get_pos(*stack_a, cheapest);
			printf("value to move = %i in pos = %i\n", cheapest, pos);
			sort(stack_a, stack_b, pos);
			display_lst(*stack_a, *stack_b);
			// i++;
		}
		sort_three(stack_a);
		while (get_lst_size(*stack_b) > 0)
		{
			count_steps_a(*stack_b);
			count_reverse_steps(*stack_a, *stack_b);
			sum_steps(*stack_b);
			display_lst_reverse(*stack_a, *stack_b);
			cheapest = get_cheapest(*stack_b);
			pos = get_pos(*stack_b, cheapest);
			printf("value to move = %i in pos = %i\n", cheapest, pos);
			sort_reverse(stack_a, stack_b, pos);
			display_lst_reverse(*stack_a, *stack_b);
			// i++;
		}
		

		// count_steps_b(*stack_b, *stack_a);








		



		// if(get_lst_size(*stack_b) == 2 && is_lst_ordered(*stack_b) == 0)
		// {
		// 	rb(stack_b);
		// }

		// // pb(stack_a, stack_b);
		// // count_steps_a(*stack_a);
		// display_lst(*stack_a, *stack_b);

		// printf("value = %i target = %i\n", (*stack_a)->value, get_target(*stack_a, *stack_b, get_lst_size(*stack_b)));
	}


/* 	free(str_args);
	free_all(args_split);

	atexit(leaks); */
	return (0);
}
