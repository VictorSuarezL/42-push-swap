/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:35:29 by vsanz-su          #+#    #+#             */
/*   Updated: 2024/03/09 16:37:33 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

// This function removes the top element from the source stack and pushes
// it onto the destination stack.
int	push(t_list **src, t_list **dst)
{
	t_list	*tmp;

	tmp = *dst;
	*dst = *src;
	*src = (*src)->next;
	(*dst)->next = tmp;
	return (1);
}

// Takes the first element from b and puts it first in a.
// Does nothing if b is empty.
char	*pa(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_b, stack_a) == 0)
		return (NULL);
	return ("pa");
}

// Takes the first element from a and puts it first in b.
// Does nothing if a is empty.
char	*pb(t_list **stack_a, t_list **stack_b)
{
	if (push(stack_a, stack_b) == 0)
		return (NULL);
	return ("pb");
}
