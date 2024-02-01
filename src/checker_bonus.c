#include <push_swap.h>

static void	check_move(char *move, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(move, "sa\n", 3) == 0)
		sa(stack_a);
	else if (ft_strncmp(move, "sb\n", 3) == 0)
		sb(stack_b);
	else if (ft_strncmp(move, "ss\n", 3) == 0)
		ss(stack_a, stack_b);
	else if (ft_strncmp(move, "pa\n", 3) == 0)
		pa(stack_a, stack_b);
	else if (ft_strncmp(move, "pb\n", 3) == 0)
		pb(stack_a, stack_b);
	else if (ft_strncmp(move, "ra\n", 3) == 0)
		ra(stack_a);
	else if (ft_strncmp(move, "rb\n", 3) == 0)
		rb(stack_b);
	else if (ft_strncmp(move, "rr\n", 3) == 0)
		rr(stack_a, stack_b);
	else if (ft_strncmp(move, "rra\n", 3) == 0)
		rra(stack_a);
	else if (ft_strncmp(move, "rrb\n", 3) == 0)
		rrb(stack_b);
	else if (ft_strncmp(move, "rrr\n", 3) == 0)
		rrr(stack_a, stack_b);
	else
		ft_error("Error");
}


int main(int ac, char *av[])
{
    if (ac < 2)
		return (-1);

	t_list **stack_a;
	t_list **stack_b;

	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));

	*stack_a = NULL;
	*stack_b = NULL;

    char *line;

	ft_init_stack(stack_a, ac, av);
    line = get_next_line(STDIN_FILENO);

    while (line)
    {
        check_move(line, stack_a, stack_b);
        free(line);
        line = get_next_line(STDIN_FILENO);
    }
    if(is_lst_ordered(*stack_a))
        ft_putendl_fd("OK", 1);
    else
    {
        ft_putendl_fd("KO", 1);
    }
    
}