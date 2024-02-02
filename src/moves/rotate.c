#include <push_swap.h>

int	rotate(t_list **lst)
{
	t_list	*new;

	if (get_lst_size(*lst) <= 1)
		return (0);
	new = *lst;
	*lst = (*lst)->next;
	new->next = NULL;
	ft_lstadd_back(lst, new);
	return (1);
}

char	*ra(t_list **stack_a)
{
	if (rotate(stack_a) == 0)
		return (NULL);
	return ("ra");
}

char	*rb(t_list **stack_b)
{
	if (rotate(stack_b) == 0)
		return (NULL);
	return ("rb");
}

char	*rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	return ("rr");
}