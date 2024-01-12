/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:06:25 by vsanz-su          #+#    #+#             */
/*   Updated: 2024/01/12 13:18:49 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

static void	leaks(void)
{
	system("leaks push_swap");
}

void	print_double_p(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
}

void print_array_of_int(int *num, int len)
{
	int i = 0;

	while(i < len)
	{
		i++;
	}
}

/* char *ft_join_args(int ac, char **av)
{
	int		i;
	char	*input;
	char	**split;

	i = 1;
	input = ft_calloc(1, 1);
	if(!input)
		return(0);
	input = av[i];
	while (++i < ac)
	{
		// input = ft_strjoin(input, " ");
		input = ft_strjoin(input, av[i]);
	}
	// split = ft_split(input, ' ');
	free(input);
	// split = ft_check_args(split);
	return input;
} */

char *ft_join_args(int ac, char **av)
{
	int i;
	char *tmp;
	char *input;

	i = 1;
	input = av[i];
	while(++i < ac)
	{

		// tmp = malloc(sizeof(char) * ft_strlen(input) + 1);
		// tmp[ft_strlen(input)] = '\0';
		// tmp = input;
		input = ft_strjoin(tmp, av[i]);
		free(tmp);
	}
	return(input);
}

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

char	**free_all(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i++]);
	}
	free(s);
	return (NULL);
}

// This function


char *ft_copy_args(int ac, char **av)
{
	int i = 1;
	int len = 0;
	char *args;

	while(i < ac)
	{
		len += ft_strlen(av[i]);
		i++;
	}

	args = (char *)malloc(sizeof(char) * (len + 1 + ac));
	if(!args)
		ft_error("Error");

	i = 1;
	int j = 0;
	int k = 0;
	while(i < ac)
	{
		j = 0;
		while(av[i][j])
		{
			args[k] = av[i][j];
			k++;
			j++;
		}
		i++;
		if(i < ac)
			args[k++] = ' ';
		else
			args[k++] = '\0';
	}
	// args[++k] = '\0';
	return(args);
}

// int ft_are_parseable(char **args_split)
// {
// 	int i;
// 	int j;

// 	i = -1;
// 	while (args_split[++i])
// 	{
// 		if (ft_strncmp(args_split[i], ft_itoa(ft_atoi(args_split[i])),
// 				ft_strlen(args_split[i]) != 0))
// 		{
// 			ft_error("Error!");
// 		}
// 	}
// 	return(1);
// }

int ft_are_parseable(char *s)
{
	if (ft_strncmp(s, ft_itoa(ft_atoi(s)), ft_strlen(s) != 0))
		return(0);

	return(1);
}

int ft_is_unique(int num, int *array, int len)
{
	int i = 0;

	while(i < len)
	{
		if(num == array[i])
			return(0);
		i++;
	}

	return(1);
}

int ft_create_args(char **s)
{
	int len = 0;
	int i = 0;
	// int j = 0;
	int num = 0;
	int *array_num;

	while(s[len])
		len++;

	array_num = (int *)malloc(sizeof(int) * (len));
	if(!array_num)
		ft_error("Error!");

	while(s[i])
	{
		if(ft_strncmp(s[i], ft_itoa(ft_atoi(s[i])), ft_strlen(s[i])) == 0)
		{
			num = ft_atoi(s[i]);
			if(ft_is_unique(num, array_num, i) == 1)
			{
				array_num[i] = num;


			}
			else
			{
				free(array_num);
				ft_error("Error!");
			}
		}
		else
		{
			free(array_num);
			ft_error("Error!");
		}
		i++;
	}
	return(0);
}

int	main(int ac, char *av[])
{
	if (ac < 1)
		return (-1);

	char *str_args;
	char **args_split;
	t_lst **lst;
	// char *foo;
	// ft_error("Error!");
	str_args = ft_copy_args(ac, av);

	args_split = ft_split(str_args, ' ');
	// print_double_p(args_split);

	ft_create_args_num(args_split);

	free(str_args);
	free_all(args_split);
	// args = ft_join_args(ac, av);
	// args = ft_check_args(args);

	// atexit(leaks);
	return (0);
}
