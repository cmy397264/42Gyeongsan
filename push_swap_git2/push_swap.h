/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whwang <whwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 13:01:47 by whwang            #+#    #+#             */
/*   Updated: 2025/07/16 15:10:06 by whwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node {
	int				data;
	int				idx;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	int		size;
	t_node	*head;
	t_node	*bottom;
}	t_stack;

int		*ft_atoi_arr(char **str, int wc);
int		*ft_merge(int *a, int *na, int asize, int nsize);
void	free_str_arr(char **str);
void	ft_hc_sort(t_stack *a, t_stack *b, int d_size);
void	ft_sort_process(int *dict, int d_size);
void	ft_stack_add(t_stack *stack, int data, int idx);
void	ft_stack_add_reverse(t_stack *stack, int data, int idx);
void	ft_stack_free(t_stack *s);
void	set_top_stack(t_stack *s, int target, int is_a);
t_stack	*ft_make_stack(void);
void	ft_stack_printf(t_stack *stack);
void	ft_sort_init(t_stack *a, int *dict, int *i_dict, int d_size);
void	ft_ps(t_stack *dest, t_stack *src, int is_a);
void	ft_ss(t_stack *a, t_stack *b);
void	ft_s(t_stack *s, int is_a, int is_print);
void	ft_rs(t_stack *s, int is_a, int is_print);
void	ft_rr(t_stack *a, t_stack *b);
void	ft_rrs(t_stack *s, int is_a, int is_print);
void	ft_chunk_sort(t_stack *a, t_stack *b, int d_size);
void	ft_rrr(t_stack *a, t_stack *b);
int		*ft_indexing(int *arr, int a_size);
int		ft_is_sorted(t_stack *s, int tc);
#endif
