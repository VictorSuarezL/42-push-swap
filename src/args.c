#include <push_swap.h>

int	get_len_dpointer(char **s)
{
	int	len;
	int	i;

	i = 1;
	len = 0;
	while (s[i])
	{
		len += ft_strlen(s[i]);
		i++;
	}
	return (len);
}
char	*ft_copy_args(int ac, char **av)
{
	int		i;
	int		len;
	char	*args;
	int		j;
	int		k;

	len = get_len_dpointer(av);
	args = (char *)malloc(sizeof(char) * (len + 1 + ac));
	if (!args)
		ft_error("Error");
	i = 1;
	j = 0;
	k = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
			args[k++] = av[i][j++];
		i++;
		if (i < ac)
			args[k++] = ' ';
		else
			args[k++] = '\0';
	}
	return (args);
}

int	ft_is_unique(int num, int *array, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (num == array[i])
			return (0);
		i++;
	}
	return (1);
}

int	is_validable(char *s)
{
	int		num;
	char	*s_num;
	int		res;

	num = ft_atoi(s);
	s_num = ft_itoa(num);
	res = ft_strncmp(s, s_num, ft_strlen(s));
	free(s_num);
	return (res);
}

int	*ft_create_args(char **s)
{
	int	i;
	int	num;
	int	*array_num;

	i = 0;
	num = 0;
	while (s[i])
		i++;
	array_num = (int *)malloc(sizeof(int) * (i + 1));
	if (!array_num)
		ft_error("Error");
	i = 0;
	while (s[i])
	{
		num = ft_atoi(s[i]);
		if (is_validable(s[i]) == 0 && ft_is_unique(num, array_num, i) == 1)
			array_num[i] = num;
		else
		{
			free(array_num);
			ft_error("Error");
		}
		i++;
	}
	return (array_num);
}

void	ft_init_list(t_list **stack, char **args_split, int *array_num)
{
	int		len;
	int		i;
	t_list	*lst;

	len = 0;
	i = 0;
	while (args_split[len])
		len++;
	while (i < len)
	{
		lst = ft_lst_new(array_num[i]);
		ft_lstadd_back(stack, lst);
		i++;
	}
}

void	ft_init_stack(t_list **stack, int ac, char **av)
{
	char	*str_args;
	char	**args_split;
	int		*array_num;
	int		len;

	len = 0;
	str_args = ft_copy_args(ac, av);
	args_split = ft_split(str_args, ' ');
	array_num = ft_create_args(args_split);
	ft_init_list(stack, args_split, array_num);
	free(array_num);
	free(str_args);
	free_all(args_split);
}
