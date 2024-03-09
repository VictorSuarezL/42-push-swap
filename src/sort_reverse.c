/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:07:01 by vsanz-su          #+#    #+#             */
/*   Updated: 2024/03/04 14:07:14 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	handle_negative_steps_sort_reverse(t_list *tmp, t_list **stack_a,
		t_list **stack_b)
{
	if (tmp->steps_a < 0 && tmp->steps_b < 0)
	{
		ft_putendl_fd(rrr(stack_a, stack_b), STDOUT_FILENO);
		tmp->steps_a++;
		tmp->steps_b++;
	}
	else if (tmp->steps_a < 0)
	{
		ft_putendl_fd(rrb(stack_b), STDOUT_FILENO);
		tmp->steps_a++;
	}
	else if (tmp->steps_b < 0)
	{
		ft_putendl_fd(rra(stack_a), STDOUT_FILENO);
		tmp->steps_b++;
	}
}

void	handle_positive_steps_sort_reverse(t_list *tmp, t_list **stack_a,
		t_list **stack_b)
{
	if (tmp->steps_a > 0 && tmp->steps_b > 0)
	{
		ft_putendl_fd(rr(stack_a, stack_b), STDOUT_FILENO);
		tmp->steps_a--;
		tmp->steps_b--;
	}
	else if (tmp->steps_a > 0)
	{
		ft_putendl_fd(rb(stack_b), STDOUT_FILENO);
		tmp->steps_a--;
	}
	else if (tmp->steps_b > 0)
	{
		ft_putendl_fd(ra(stack_a), STDOUT_FILENO);
		tmp->steps_b--;
	}
}

void	sort_reverse(t_list **stack_a, t_list **stack_b, int pos)
{
	t_list	*tmp;

	tmp = get_node(*stack_b, pos);
	while (tmp->steps_a != 0 || tmp->steps_b != 0)
	{
		handle_negative_steps_sort_reverse(tmp, stack_a, stack_b);
		handle_positive_steps_sort_reverse(tmp, stack_a, stack_b);
	}
	ft_putendl_fd(pa(stack_a, stack_b), STDOUT_FILENO);
}
