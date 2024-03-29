/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:36:07 by vsanz-su          #+#    #+#             */
/*   Updated: 2024/03/09 16:36:22 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	swap(t_list **stack)
{
	t_list	*tmp;

	if (get_lst_size(*stack) <= 1)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	return (1);
}

char	*sa(t_list **stack_a)
{
	if (swap(stack_a) == 0)
		return (NULL);
	return ("sa");
}

char	*sb(t_list **stack_b)
{
	if (swap(stack_b) == 0)
		return (NULL);
	return ("sb");
}

char	*ss(t_list **stack_a, t_list **stack_b)
{
	if (swap(stack_a) == 0 && swap(stack_b) == 0)
		return (NULL);
	return ("ss");
}
