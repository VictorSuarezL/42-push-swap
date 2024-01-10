/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:06:25 by vsanz-su          #+#    #+#             */
/*   Updated: 2024/01/10 17:02:09 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>


//!!!!! PONER FLAGS EN MAKEFILE

static void leaks(void){
	system("leaks push_swap");
}

void print_double_p(char **s)
{
	int i;

	i = 0;
	while(s[i])
	{
		printf("%i = %s\n", i, s[i]);
		i++;
	}
}

void ft_check_args(int ac, char **av)
{
	int i;
	char **args;

	i = 0;
	if(ac == 2)
	{
		args = ft_split(av[1], ' ');
		print_double_p(args);
	}
	else
	{
		i = 1;
		args = av;

	}
}

int main(int ac, char *av[])
{
	if(ac < 1)
		return -1;

	int i;
	int j;
	char *input;

	i = 1;
	j = 0;

	//ft_check_args(ac, av);
	// if(ac == 1)
	// 	input = av[1];
	// else
	// {
	input = av[i++];
	while(i < ac)
	{
		input = ft_strjoin(input, " ");
		input = ft_strjoin(input, av[i]);
		// if(i < (ac - 1))
		// 	input = ft_strjoin(input, " ");
		i++;
	}
	// }



	printf("input = %s\n", input);

	// while(i < ac)
	// {
	// 	input = ft_strjoin(input, av[i++]);
	// }
	// printf("input = %s\n", input);
	// printf("\t\t\t\t<---------------------------->");
	// atexit(leaks);
	return(0);
}
