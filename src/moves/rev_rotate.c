#include <push_swap.h>

int	rev_rotate(t_list **lst)
{
	t_list	*tmp;

	if (get_lst_size(*lst) <= 1)
		return (0);
	tmp = get_node(*lst, get_lst_size(*lst) - 1);
	get_node(*lst, get_lst_size(*lst) - 2)->next = NULL;
	tmp->next = *lst;
	*lst = tmp;
	return (1);
}

char	*rra(t_list **stack_a)
{
	if (rev_rotate(stack_a) == 0)
		return (NULL);
	return ("rra");
}

char	*rrb(t_list **stack_b)
{
	if (rev_rotate(stack_b) == 0)
		return (NULL);
	return ("rrb");
}

char	*rrr(t_list **stack_a, t_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	return ("rrr");
}