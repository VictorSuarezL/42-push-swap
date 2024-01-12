/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsanz-su <vsanz-su@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 09:42:36 by vsanz-su          #+#    #+#             */
/*   Updated: 2024/01/12 12:48:29 by vsanz-su         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

char **ft_split_args(int ac, char **av);
char **ft_check_args(char **split);
void	print_double_p(char **s);



// Stack
typedef struct s_list
{
	int				index;
	int				value;
	struct s_list	*next;
}					t_lst;

#include "libft/libft.h"

#endif
