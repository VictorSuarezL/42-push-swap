#include <push_swap.h>

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
