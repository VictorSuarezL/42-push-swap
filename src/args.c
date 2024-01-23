#include <push_swap.h>

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
	int len = 0;

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