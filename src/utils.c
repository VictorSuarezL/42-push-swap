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