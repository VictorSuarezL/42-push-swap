/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:06:25 by vsanz-su          #+#    #+#             */
/*   Updated: 2024/01/11 13:54:39 by vsanz-su         ###   ########.fr       */
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
		printf("%i = %s\n", i, s[i]);
		i++;
	}
}

// char *ft_join_args(int ac, char **av)
// {
// 	int		i;
// 	char	*input;
// 	char	**split;

// 	i = 1;
// 	input = ft_calloc(1, 1);
// 	if(!input)
// 		return(0);
// 	input = av[i];
// 	while (++i < ac)
// 	{
// 		// input = ft_strjoin(input, " ");
// 		input = ft_strjoin(input, av[i]);
// 	}
// 	// split = ft_split(input, ' ');
// 	free(input);
// 	// split = ft_check_args(split);
// 	return input;
// }

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

void ft_error(void)
{
	printf("Error\n");
	exit(EXIT_FAILURE);
}

// This function
char **ft_check_args(char **split)
{
	int i;
	int j;

	i = -1;
	while (split[++i])
	{
		if (ft_strncmp(split[i], ft_itoa(ft_atoi(split[i])),
				ft_strlen(split[i]) != 0))
		{
			// printf("Error!");
			ft_error();
		}
	}
	return(split);
}

int	main(int ac, char *av[])
{
	if (ac < 1)
		return (-1);

	char *args;
	char *foo;
	args = ft_join_args(ac, av);
	printf("%s\n", args);
	// args = ft_check_args(args);
	// print_double_p(args);

	printf("<<<<<<----------->>>>>>");
	atexit(leaks);
	return (0);
}
