#include <push_swap.h>

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
	ft_putendl_fd("rra", STDOUT_FILENO);
}

void rrb(t_list **stack_b)
{
	if(rev_rotate(stack_b) == 0)
		return;
	ft_putendl_fd("rrb", STDOUT_FILENO);
}

void rrr(t_list **stack_a, t_list **stack_b)
{
	// if(rev_rotate(stack_a) == 0 && rev_rotate(stack_b) == 0)
	// 	return;
	rev_rotate(stack_a);
	rev_rotate(stack_b);

	ft_putendl_fd("rrr", STDOUT_FILENO);
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
	ft_putendl_fd("ra", STDOUT_FILENO);
}

void rb(t_list **stack_b)
{
	if(rotate(stack_b) == 0)
		return;
	ft_putendl_fd("rb", STDOUT_FILENO);
}

void rr(t_list **stack_a, t_list **stack_b)
{
	// if(rotate(stack_a) == 0 && rotate(stack_b) == 0)
	// 	return;
	rotate(stack_a);
	rotate(stack_b);
	ft_putendl_fd("rr", STDOUT_FILENO);
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
	ft_putendl_fd("pa", STDOUT_FILENO);
}

// Toma el primer elemento de a y lo pone el primero en b. No hace nada si a está vacio.
void pb(t_list **stack_a, t_list **stack_b)
{
	if(push(stack_a, stack_b) == 0)
		return;
	ft_putendl_fd("pb", STDOUT_FILENO);
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
	ft_putendl_fd("sa", STDOUT_FILENO);
}

void sb(t_list **stack_b)
{
	// swap(stack_a);
	if(swap(stack_b) == 0)
		return;
	ft_putendl_fd("sb", STDOUT_FILENO);
}

void ss(t_list **stack_a, t_list **stack_b)
{
	if(swap(stack_a) == 0 && swap(stack_b) == 0)
		return;
	ft_putendl_fd("ss", STDOUT_FILENO);
}
