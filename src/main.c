/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:06:25 by vsanz-su          #+#    #+#             */
/*   Updated: 2024/03/09 17:44:13 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	loop(t_list **stack_a, t_list **stack_b)
{
	int	pos;
	int	cheapest;

	pos = 0;
	if (get_lst_size(*stack_a) > 3)
	{
		ft_putendl_fd(pb(stack_a, stack_b), STDOUT_FILENO);
		ft_putendl_fd(pb(stack_a, stack_b), STDOUT_FILENO);
	}
	while (get_lst_size(*stack_a) > 3)
	{
		count_steps_a(*stack_a);
		count_steps_b(*stack_a, *stack_b);
		sum_steps(*stack_a);
		cheapest = get_cheapest(*stack_a);
		pos = get_pos(*stack_a, cheapest);
		sort(stack_a, stack_b, pos);
	}
}

static void	rev_loop(t_list **stack_a, t_list **stack_b)
{
	while (get_lst_size(*stack_b) > 0)
	{
		count_steps_a(*stack_b);
		count_reverse_steps(*stack_a, *stack_b);
		sum_steps(*stack_b);
		sort_reverse(stack_a, stack_b, 0);
	}
}

static void	loop_a(t_list **stack_a)
{
	int	pos;

	pos = 0;
	if (is_lst_ordered(*stack_a) == 0)
	{
		count_steps_a(*stack_a);
		pos = get_pos(*stack_a, get_min(*stack_a));
		sort_a(stack_a, pos);
	}
}

int	main(int ac, char *av[])
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (ac < 1)
		return (-1);
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	ft_init_stack(stack_a, ac, av);
	if (is_lst_ordered(*stack_a))
	{
		free_list(stack_a);
		free_list(stack_b);
		return (0);
	}
	else
	{
		loop(stack_a, stack_b);
		sort_three(stack_a);
		rev_loop(stack_a, stack_b);
		loop_a(stack_a);
	}
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
