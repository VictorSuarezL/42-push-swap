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

void free_list(t_list **list)
{
    t_list *tmp;

    while (*list)
    {
        tmp = (*list)->next;
        free(*list);
        *list = tmp;
    }
	free(list);
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
		return 0;
	}
	else
	{
		/////// DISPLAY VARIABLE:
		// display = 0;
		
		int pos;
		int i = 0;
		int cheapest;

		pb(stack_a, stack_b);
		pb(stack_a, stack_b);

		// if(display == 1)
		// 	display_lst(*stack_a, *stack_b);
		
		while (get_lst_size(*stack_a) > 3)
		{
			count_steps_a(*stack_a);
			count_steps_b(*stack_a, *stack_b);
			sum_steps(*stack_a);
			cheapest = get_cheapest(*stack_a);
			pos = get_pos(*stack_a, cheapest);
			// if(display == 1)
			// {
			// 	printf("value to move = %i in pos = %i\n", cheapest, pos);
			// 	display_lst(*stack_a, *stack_b);
			// }
			sort(stack_a, stack_b, pos);
		}
		sort_three(stack_a);
		// if (display == 1)
		// {
		// 	display_lst(*stack_a, *stack_b);
		// }
		

		i = 0;
		while (get_lst_size(*stack_b) > 0)
		{
			count_steps_a(*stack_b);
			count_reverse_steps(*stack_a, *stack_b);
			sum_steps(*stack_b);
			cheapest = get_cheapest(*stack_b);
			pos = get_pos(*stack_b, cheapest);
			// if(display == 1)
			// {
			// 	printf("value to move = %i in pos = %i\n", cheapest, pos);
			// 	display_lst_reverse(*stack_a, *stack_b);
			// }
			sort_reverse(stack_a, stack_b, 0);
		}
		// if(display == 1)
		// 	display_lst(*stack_a, *stack_b);
		if(is_lst_ordered(*stack_a) == 0)
		{
			count_steps_a(*stack_a);
			pos = get_pos(*stack_a, get_min(*stack_a));
			sort_a(stack_a, pos);
			// if(display == 1)
			// 	display_lst(*stack_a, *stack_b);
		}
	}
/* 	free(str_args);
	free_all(args_split);

	atexit(leaks); */
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
