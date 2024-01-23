#include <push_swap.h>
#include <stdio.h>

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