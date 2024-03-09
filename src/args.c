/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:30:55 by vsanz-su          #+#    #+#             */
/*   Updated: 2024/03/09 17:42:10 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	is_validable(char *s)
{
	int		num;
	char	*s_num;
	int		res;

	num = ft_atoi(s);
	s_num = ft_itoa(num);
	res = ft_strncmp(s, s_num, ft_strlen(s));
	free(s_num);
	return (res);
}

int	*ft_create_args(char **s)
{
	int	i;
	int	num;
	int	*array_num;

	i = 0;
	num = 0;
	while (s[i])
		i++;
	array_num = (int *)malloc(sizeof(int) * (i + 1));
	if (!array_num)
		ft_error("Error");
	i = 0;
	while (s[i])
	{
		num = ft_atoi(s[i]);
		if (is_validable(s[i]) == 0 && ft_is_unique(num, array_num, i) == 1)
			array_num[i] = num;
		else
		{
			free(array_num);
			ft_error("Error");
		}
		i++;
	}
	return (array_num);
}

void	ft_init_list(t_list **stack, char **args_split, int *array_num)
{
	int		len;
	int		i;
	t_list	*lst;

	len = 0;
	i = 0;
	while (args_split[len])
		len++;
	while (i < len)
	{
		lst = ft_lst_new(array_num[i]);
		ft_lstadd_back(stack, lst);
		i++;
	}
}

void	ft_init_stack(t_list **stack, int ac, char **av)
{
	char	*str_args;
	char	**args_split;
	int		*array_num;

	str_args = ft_copy_args(ac, av);
	args_split = ft_split(str_args, ' ');
	array_num = ft_create_args(args_split);
	ft_init_list(stack, args_split, array_num);
	free(array_num);
	free(str_args);
	free_all(args_split);
}
