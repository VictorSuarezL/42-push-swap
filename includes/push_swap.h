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
	struct s_list	*next;
}					t_list;

#include "libft/libft.h"

// HELPER FORBIDEN FUNCTIONS
void print_double_p(char **s);
void print_array_of_int(int *num, int len);
void print_list(t_list *lst);

// UTILS
void ft_error(char *msg);
char **free_all(char **s);

// ARGS FUNCTIONS:
char *ft_copy_args(int ac, char **av);
int ft_is_unique(int num, int *array, int len);
int *ft_create_args(char **s);
t_list *ft_lst_new(int value);
t_list *ft_lstlast(t_list *lst);
void ft_lstadd_back(t_list **lst, t_list *new);
void ft_init_stack(t_list **stack, int ac, char **av);



#endif
