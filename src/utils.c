/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:10:41 by vsanz-su          #+#    #+#             */
/*   Updated: 2024/03/04 14:10:43 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	free_all(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i++]);
	}
	free(s);
}

void	free_list(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		free(*list);
		*list = tmp;
	}
	free(list);
}
