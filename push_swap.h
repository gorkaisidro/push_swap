/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gisidro- <gisidro-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:10:10 by gisidro-          #+#    #+#             */
/*   Updated: 2025/10/10 13:53:47 by gisidro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// write, open, close, read
# include <unistd.h>
//malloc, free, exit
# include <stdlib.h>
// boolean
# include <stdbool.h>
// INT_MAX, INT_MIN, LONG_MAX, LONG_MIN
# include <limits.h>
// printf, scanf, fopen, fclose, fread
# include <stdio.h>

// error messages
# define REPEAT "Error\n"
# define OVERFLOW "Error\n"
# define SYNTAX "Error\n"
# define MALLOC_ERROR "Error\n"

// operations
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"
# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// init / free
void		stack_init(t_stack **a, char **av, int ac, bool flag_ac_2);
long long	*normalize(long long *numbers, int len);
void		free_matrix(char **av);
void		free_stack(t_stack **stack);
void		error_free(t_stack **a, char **av, bool flag_ac_2);

// error checks
int			error_syntax(char *str_nbr);
int			error_repetition(long long *stack, int len);

// operations
void		push(t_stack **destRef, t_stack **sourceRef, char *str);
void		rotate(t_stack **headRef, char *str);
void		rr(t_stack **a, t_stack **b);
void		reverse_rotate(t_stack **headRef, char *str);
void		rrr(t_stack **a, t_stack **b);
void		swap(t_stack **headRef, char *str);
void		ss(t_stack **a, t_stack **b);

// utils
t_stack		*find_last_node(t_stack *head);
void		append_node(t_stack **headRef, int nbr);
int			stack_len(t_stack *stack);
bool		stack_sorted(t_stack *stack);

// sorting
void		radix_sort(t_stack **a, t_stack **b, int len);
void		sort_three(t_stack **a);
void		sort_four_and_five(t_stack **a, t_stack **b);

// misc
void		user_message(char *str);
void		print_list(t_stack *list);

// memory
void		*xmalloc(size_t size);

// others
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dsize);
char		**ft_split(const char *s, char c);
long long	ft_atoll(const char *str);

#endif
