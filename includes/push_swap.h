/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:42:36 by vsanz-su          #+#    #+#             */
/*   Updated: 2024/01/15 12:56:12 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// Stack
typedef struct s_list
{
	int				index;
	int				value;
	int 			steps_a;
	int				steps_b;
	int 			total;
	struct s_list	*next;
}					t_list;

#include "libft/libft.h"

int display;
// HELPER FORBIDEN FUNCTIONS
void print_double_p(char **s);
void print_array_of_int(int *num, int len);
void print_list(t_list *lst);
void display_lst(t_list *stack_a, t_list *stack_b);
void display_lst_reverse(t_list *stack_a, t_list *stack_b);

// UTILS
void ft_error(char *msg);
char **free_all(char **s);
int is_lst_ordered(t_list *lst);
int get_lst_size(t_list *lst);
t_list *get_node(t_list *stack, int pos);
int get_min(t_list *lst);
int get_max(t_list *lst);
int get_pos(t_list *lst, int num);


// ARGS FUNCTIONS:
char *ft_copy_args(int ac, char **av);
int ft_is_unique(int num, int *array, int len);
int *ft_create_args(char **s);
t_list *ft_lst_new(int value);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_init_stack(t_list **stack, int ac, char **av);

// MOVES:
int rev_rotate(t_list **lst);
void rra(t_list **stack_a);
void rrb(t_list **stack_b);
void rrr(t_list **stack_a, t_list **stack_b);
int rotate(t_list **lst);
void ra(t_list **stack_a);
void rb(t_list **stack_b);
void rr(t_list **stack_a, t_list **stack_b);
int push(t_list **src, t_list **dst);
void pa(t_list **stack_a, t_list **stack_b);
void pb(t_list **stack_a, t_list **stack_b);
int swap(t_list **stack);
void sa(t_list **stack_a);
void sb(t_list **stack_b);
void ss(t_list **stack_a, t_list **stack_b);

// SORT:
void count_steps_a(t_list *stack_a);
void sort_three(t_list **lst);
int get_target(t_list *stack_a, t_list *stack_b, int size_b);
void count_steps_b(t_list *stack_a, t_list *stack_b);
int get_reverse_target(t_list *dst, t_list *src, int size_dst);
void count_reverse_steps(t_list *dst, t_list *src);
void sum_steps(t_list *stack_a);
int get_cheapest(t_list *stack_a);
void sort(t_list **stack_a, t_list **stack_b, int pos);
void sort_reverse(t_list **stack_a, t_list **stack_b, int pos);
void sort_a(t_list **stack_a, int pos);

#endif
