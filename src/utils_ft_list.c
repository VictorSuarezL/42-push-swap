#include <push_swap.h>

t_list *ft_lst_new(int value)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
	node->next = NULL;
	return (node);
}

t_list	*ft_lstlast(t_list *lst)
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (*lst == NULL)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

int is_lst_ordered(t_list *lst)
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