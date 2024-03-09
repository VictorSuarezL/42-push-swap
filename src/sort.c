/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:08:00 by vsanz-su          #+#    #+#             */
/*   Updated: 2024/03/04 14:08:17 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	handle_negative_steps_sort(t_list *tmp, t_list **stack_a,
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
		ft_putendl_fd(rra(stack_a), STDOUT_FILENO);
		tmp->steps_a++;
	}
	else if (tmp->steps_b < 0)
	{
		ft_putendl_fd(rrb(stack_b), STDOUT_FILENO);
		tmp->steps_b++;
	}
}

void	handle_positive_steps_sort(t_list *tmp, t_list **stack_a,
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
		ft_putendl_fd(ra(stack_a), STDOUT_FILENO);
		tmp->steps_a--;
	}
	else if (tmp->steps_b > 0)
	{
		ft_putendl_fd(rb(stack_b), STDOUT_FILENO);
		tmp->steps_b--;
	}
}

void	sort(t_list **stack_a, t_list **stack_b, int pos)
{
	t_list	*tmp;

	tmp = get_node(*stack_a, pos);
	while (tmp->steps_a != 0 || tmp->steps_b != 0)
	{
		handle_negative_steps_sort(tmp, stack_a, stack_b);
		handle_positive_steps_sort(tmp, stack_a, stack_b);
	}
	ft_putendl_fd(pb(stack_a, stack_b), STDOUT_FILENO);
}

void	sort_three(t_list **lst)
{
	int	min_pos;
	int	max_pos;

	while (is_lst_ordered(*lst) == 0)
	{
		min_pos = get_pos(*lst, get_min(*lst));
		max_pos = get_pos(*lst, get_max(*lst));
		if (max_pos == 0 && min_pos == 2)
			ft_putendl_fd(ra(lst), STDOUT_FILENO);
		else if (max_pos == 1 && min_pos == 0)
			ft_putendl_fd(sa(lst), STDOUT_FILENO);
		else if (max_pos == 0 && min_pos == 1)
			ft_putendl_fd(ra(lst), STDOUT_FILENO);
		else if (max_pos == 1 && min_pos == 2)
			ft_putendl_fd(rra(lst), STDOUT_FILENO);
		else if (max_pos == 2 && min_pos == 1)
			ft_putendl_fd(sa(lst), STDOUT_FILENO);
	}
}

void	sort_a(t_list **stack_a, int pos)
{
	t_list	*tmp;

	tmp = get_node(*stack_a, pos);
	while (tmp->steps_a != 0)
	{
		if (tmp->steps_a > 0)
		{
			ft_putendl_fd(ra(stack_a), STDOUT_FILENO);
			tmp->steps_a--;
		}
		else if (tmp->steps_a < 0)
		{
			ft_putendl_fd(rra(stack_a), STDOUT_FILENO);
			tmp->steps_a++;
		}
	}
}
