#include <push_swap.h>

int get_lst_size(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list	*get_node(t_list *stack, int pos)
{
	int		i;
	t_list	*node;

	i = 0;
	node = stack;
	while (i < pos)
	{
		node = node->next;
		i++;
	}
	return (node);
}

int	get_min(t_list *lst)
{
	int	min;

	if (lst)
	{
		min = lst->value;
		lst = lst->next;
	}
	while (lst)
	{
		if (lst->value < min)
			min = lst->value;
		lst = lst->next;
	}
	return (min);
}

int	get_max(t_list *lst)
{
	int	max;

	if (lst)
	{
		max = lst->value;
		lst = lst->next;
	}
	while (lst)
	{
		if (lst->value > max)
			max = lst->value;
		lst = lst->next;
	}
	return (max);
}

int	get_pos(t_list *lst, int num)
{
	int pos = 0;

	while (lst->value != num)
	{
		pos++;
		lst = lst->next;
	}
	return (pos);
}