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


int get_lst_size(t_list *lst)
{
	int i = 0;

	while(lst)
	{
		lst = lst->next;
		i++;
	}
	return(i);
}

//This function change the pointer to the node given by position
t_list *get_node(t_list *stack, int pos)
{
	int i = 0;
	t_list *node;
	
	node = stack;
	i = 0;
	while(i < pos)
	{
		node = node->next;
		i++;
	}
	return node;
}

int rev_rotate(t_list **lst)
{
	t_list *tmp;

	if(get_lst_size(*lst) <= 1)
		return 0;
	
	tmp = get_node(*lst, get_lst_size(*lst) - 1);
	get_node(*lst, get_lst_size(*lst) - 2)->next = NULL;
	tmp->next = *lst;
	*lst = tmp;
	return 1;
}

void rra(t_list **stack_a)
{
	if(rev_rotate(stack_a) == 0)
		return;
	ft_putendl_fd("rra", 1);
}

void rrb(t_list **stack_b)
{
	if(rev_rotate(stack_b) == 0)
		return;
	ft_putendl_fd("rrb", 1);
}

void rrr(t_list **stack_a, t_list **stack_b)
{
	if(rev_rotate(stack_a) == 0 && rev_rotate(stack_b) == 0)
		return;
	ft_putendl_fd("rrr", 1);
}

int rotate(t_list **lst)
{
	t_list *new;
	if(get_lst_size(*lst) <= 1)
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
	if(rotate(stack_a) == 0 && rotate(stack_b) == 0)
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

	if(get_lst_size(*stack) <= 1)
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
	if(swap(stack_a) == 0 && swap(stack_b) == 0)
		return;
	ft_putendl_fd("ss", 1);
}

void display_lst(t_list *stack_a, t_list *stack_b)
{
	if (stack_a == NULL && stack_b == NULL)
		return;

	printf("stack_a\tstack_b\n");

	while (stack_a != NULL || stack_b != NULL)
	{
		if (stack_a != NULL)
		{
			printf("%i | %i\t", stack_a->value, stack_a->steps_a);
			stack_a = stack_a->next;
		}
		else
		{
			printf("\t");
		}

		if (stack_b != NULL)
		{
			printf("%i", stack_b->value);
			stack_b = stack_b->next;
		}

		printf("\n");
	}
	printf("\t\t<------>\n");
}

void count_steps_a(t_list *stack_a)
{
	int pos;
	int size_lst;

	size_lst = get_lst_size(stack_a);
	pos = 0;
	while(stack_a)
	{
		if (pos <= (size_lst/2))
		{
			stack_a->steps_a = pos;
		}
		else
		{
			stack_a->steps_a = size_lst - pos;
		}
		stack_a = stack_a->next;
		pos++;
	}
}

int get_min(t_list *lst)
{
	int min;

	if(lst)
	{
		min = lst->value;
		lst = lst->next;
	}

	while(lst)
	{
		if(lst->value < min)
			min = lst->value;
		lst = lst->next;
	}
	return min;
}

int get_max(t_list *lst)
{
	int max;

	if(lst)
	{
		max = lst->value;
		lst = lst->next;
	}

	while(lst)
	{
		if(lst->value > max)
			max = lst->value;
		lst = lst->next;
	}
	return max;
}

int get_pos(t_list *lst, int target)
{
	int pos = 0;

	while (lst->value != target)
	{
		pos++;
		lst = lst->next;
	}
	return pos;
}

int get_target(t_list *stack_a, t_list *stack_b, int size_b)
{
	int target;
	t_list *tmp_b;
	int value_b;

	tmp_b = stack_b;
	target = 0;

	if (stack_a->value < get_min(stack_b) || stack_a->value > get_max(stack_b))
	{
		target = get_max(stack_b);
	}
	else
	{
		while(stack_b->next)
		{
			// printf("\tvalue_b = %i\n", stack_b->value);
			if (stack_a->value < stack_b->value && stack_a->value > stack_b->next->value)
			{
				target = stack_b->next->value;
			}
			stack_b = stack_b->next;
		}
	}
	return target;
}

void count_steps_b(t_list *stack_a, t_list *stack_b)
{
	int size_b;
	int target;

	size_b = get_lst_size(stack_b);

	while (stack_a)
	{
		target = get_target(stack_a, stack_b, size_b);
		printf("value_a = %i target = %i\n", stack_a->value, target);
		stack_a = stack_a->next;
		// if (get_pos(stack_b, target))
		// {

		// 	/* code */
		// }
		
		


	}
	


}

int	main(int ac, char *av[])
{
	if (ac < 1)
		return (-1);


	t_list **stack_a;
	t_list **stack_b;

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

		pb(stack_a, stack_b);
		pb(stack_a, stack_b);

		if(get_lst_size(*stack_b) == 2 && ft_stack_sorted(*stack_b) == 0)
		{
			rb(stack_b);
		}

		// pb(stack_a, stack_b);
		// count_steps_a(*stack_a);
		display_lst(*stack_a, *stack_b);

		// printf("value = %i target = %i\n", (*stack_a)->value, get_target(*stack_a, *stack_b, get_lst_size(*stack_b)));
		count_steps_b(*stack_a, *stack_b);




		// rra(stack_a);
		// display_lst(*stack_a, *stack_b);

		// pb(stack_a, stack_b);
		// pb(stack_a, stack_b);
		// pb(stack_a, stack_b);
		// display_lst(*stack_a, *stack_b);

		// rr(stack_a, stack_b);
		// display_lst(*stack_a, *stack_b);

		// pa(stack_a, stack_b);
		// display_lst(*stack_a, *stack_b);
	}


/* 	free(str_args);
	free_all(args_split);

	atexit(leaks); */
	return (0);
}
