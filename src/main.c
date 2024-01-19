/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:06:25 by vsanz-su          #+#    #+#             */
/*   Updated: 2024/01/19 16:52:13 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <stdio.h>

static void	leaks(void)
{
	system("leaks push_swap");
}

void print_double_p(char **s)
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
		printf(" %i,", num[i]);
		i++;
	}
	printf("\n");
}

void print_list(t_list *lst)
{
	while(lst)
	{
		printf("%i\n", lst->value);
		lst = lst->next;
	}
}

void ft_error(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

char **free_all(char **s)
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

/* int ft_are_parseable(char *s)
{
	if (ft_strncmp(s, ft_itoa(ft_atoi(s)), ft_strlen(s) != 0))
		return(0);

	return(1);
}
 */

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

int *ft_create_args(char **s)
{
	int len = 0;
	int i = 0;
	int num = 0;
	int *array_num;

	while(s[len])
		len++;

	array_num = (int *)malloc(sizeof(int) * (len + 1));
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
	return(array_num);
}

t_list *ft_lst_new(int value)
{
	t_list *node;

	node = (t_list *)malloc(sizeof(t_list));
	if(!node)
		return NULL;
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return(node);
}

t_list *ft_lstlast(t_list *lst)
{
	t_list	*end;

	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!lst->next)
		{
			end = lst;
		}
		lst = lst->next;
	}
	return (end);
}

void ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

void ft_init_stack(t_list **stack, int ac, char **av)
{
	char *str_args;
	char **args_split;
	int *array_num;
	int len;

	str_args = ft_copy_args(ac, av);
	args_split = ft_split(str_args, ' ');
	array_num = ft_create_args(args_split);

	while(args_split[len])
		len++;

	print_array_of_int(array_num, len);
	t_list *lst;
	int i;

	i = 0;
	while(i < len)
	{
		lst = ft_lst_new(array_num[i]);
		ft_lstadd_back(stack, lst);
		i++;
	}

	free(str_args);
	free_all(args_split);
}

int ft_stack_sorted(t_list *lst)
{
	if(!lst)
		ft_error("Error!");

	while(lst->next)
	{
		if(lst->value > lst->next->value)
			return(0);
		lst = lst->next;
	}
	return 1;
}

/* void ft_swap(t_list *lst)
{
	int swap;

	swap = lst->next->value;
	lst->next->value = lst->value;
	lst->value = swap;
} */

int lst_size(t_list *lst)
{
	int i = 0;

	while(lst)
	{
		lst = lst->next;
		i++;
	}
	return(i);
}

int rotate(t_list **lst)
{
	t_list *new;
	if(lst_size(*lst) <= 1)
		return 0;
	new = *lst;
	*lst = (*lst)->next;
	new->next = NULL;
	ft_lstadd_back(lst, new);
	return 1;
}

void ra(t_list **stack_a)
{
	if(rotate(stack_a) == 0)
		return;
	ft_putendl_fd("ra", 1);
}

void rb(t_list **stack_b)
{
	if(rotate(stack_b) == 0)
		return;
	ft_putendl_fd("rb", 1);
}

void rr(t_list **stack_a, t_list **stack_b)
{
	if(rotate(stack_a) && rotate(stack_b) == 0)
		return;
	ft_putendl_fd("rr", 1);
}

int push(t_list **src, t_list **dst)
{
	t_list *tmp;

	tmp = *dst;
	*dst = *src;
	*src = (*src)->next;
	(*dst)->next = tmp;
	return 1;
}

// Toma el primer elemento de b y lo pone el primero en a. No hace nada si b está vacio.
void pa(t_list **stack_a, t_list **stack_b)
{
	// swap(stack_a);
	if(push(stack_b, stack_a) == 0)
		return;
	ft_putendl_fd("pa", 1);
}

// Toma el primer elemento de a y lo pone el primero en b. No hace nada si a está vacio.
void pb(t_list **stack_a, t_list **stack_b)
{
	if(push(stack_a, stack_b) == 0)
		return;
	ft_putendl_fd("pb", 1);
}

int swap(t_list **stack)
{
	t_list *tmp;

	if(lst_size(*stack) <= 1)
		return 0;
	// ft_putendl_fd("sa", 1);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	return 1;
}

void sa(t_list **stack_a)
{
	// swap(stack_a);
	if(swap(stack_a) == 0)
		return;
	ft_putendl_fd("sa", 1);
}

void sb(t_list **stack_b)
{
	// swap(stack_a);
	if(swap(stack_b) == 0)
		return;
	ft_putendl_fd("sa", 1);
}

void ss(t_list **stack_a, t_list **stack_b)
{
	if(swap(stack_a) && swap(stack_b) == 0)
		return;
	ft_putendl_fd("ss", 1);
}

int	main(int ac, char *av[])
{
	if (ac < 1)
		return (-1);

/* 	char *str_args;
	char **args_split;
	int *array_num; */
	t_list **stack_a;
	t_list **stack_b;
/*
	// char *foo;
	// ft_error("Error!");
	str_args = ft_copy_args(ac, av);

	args_split = ft_split(str_args, ' ');
	// print_double_p(args_split);

	array_num = ft_create_args(args_split);
	// print_array_of_int(&array_num[1], array_num[0]);
 */
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));

	*stack_a = NULL;
	*stack_b = NULL;

	ft_init_stack(stack_a, ac, av);
	if(ft_stack_sorted(*stack_a))
	{
		printf("Ordered!\n");
	}
	else
	{
		// print_list(*stack_a);
		printf("Not Ordered!\n");

		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		ft_putendl_fd("stack_a", 1);
		print_list(*stack_a);
		ft_putendl_fd("stack_b", 1);
		print_list(*stack_b);

		rr(stack_a, stack_b);
		ft_putendl_fd("stack_a", 1);
		print_list(*stack_a);
		ft_putendl_fd("stack_b", 1);
		print_list(*stack_b);

		// pa(stack_a, stack_b);

		// ft_putendl_fd("stack_a", 1);
		// print_list(*stack_a);
		// ft_putendl_fd("stack_b", 1);
		// print_list(*stack_b);

	}


	/* 	free(str_args);
	free_all(args_split); */
	// args = ft_join_args(ac, av);
	// args = ft_check_args(args);

	// atexit(leaks);
	return (0);
}
