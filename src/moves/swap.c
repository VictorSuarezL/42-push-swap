#include <push_swap.h>

int	swap(t_list **stack)
{
	t_list	*tmp;

	if (get_lst_size(*stack) <= 1)
		return (0);
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	return (1);
}

char	*sa(t_list **stack_a)
{
	// swap(stack_a);
	if (swap(stack_a) == 0)
		return (NULL);
	// ft_putendl_fd("sa", STDOUT_FILENO);
	return ("sa");
}

char	*sb(t_list **stack_b)
{
	// swap(stack_a);
	if (swap(stack_b) == 0)
		return (NULL);
	// ft_putendl_fd("sb", STDOUT_FILENO);
	return ("sb");
}

char	*ss(t_list **stack_a, t_list **stack_b)
{
	if (swap(stack_a) == 0 && swap(stack_b) == 0)
		return (NULL);
	// ft_putendl_fd("ss", STDOUT_FILENO);
	return ("ss");
}