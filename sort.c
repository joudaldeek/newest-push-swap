/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaldeek <jaldeek@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:46:20 by jaldeek           #+#    #+#             */
/*   Updated: 2026/01/21 15:14:25 by jaldeek          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	Simple(t_stack** a, t_stack** taila, t_stack** b, t_stack** tailb)
{
	int rotations;
	int len;
	int i;

	len = 0;
	rotations = 0;
	pb(a,b);
	pb(a,b);
	len += 2;
	if((*b) ->value < (*b)->previous->value)
		sb(b);
	while (!(*a))
	{
		i = 0;
		while ( *b && ((*b) ->value > (*a) ->value) && i < len) 
		{
			rb(b, tailb);
			rotations++;
			i++;
		}
		pb(a, b);
		len++;
		while (rotations--> 0)
			rrb(b, tailb);
	}
}
void sort_p(int *p)
{
}
int find_index(int *p, int value)
{
	int	i;

	i = 0;
	while (p[i])
	{
		if(p[i] == value)
			return (i);
		i++;
	}
	return (-1);
}
void set_index(t_stack **a, int *p)
{
	t_stack *tmp;

	tmp = *a
	while (tmp)
	{
		tmp -> value = find_index(p, tmp ->value);
		tmp = tmp ->next;
	}
}
int	window_size(int len)
{
	if(len <= 100)
		return (20);
	else 
		return (45);
}
void	push_to_b(t_stack **a, t_stack **taila, t_stack **b, t_stack **tailb)
{
	int	low;
	int	high;
	int	window; 

	window = window_size(stack_len(a));
	low = 0;
	high = window;
	while (*a)
	{
		if((*a) -> value >= low && (*a) -> value <= high)
		{
			pb(a,b);
			if((*a) -> value < low + window / 2)
				rb(b, tailb);
			low++;
			high++;
		}
		else if ((*a) -> value < low)
		{
			pb(a,b);
			rb(b, tailb);
			low++;
			high++;
		}
		else 
			ra(a,taila);
	}
}
void	push_back(t_stack **a, t_stack **b)
{
	if (!((*b) -> previous))
		return;
	while (*b)
	{
		if ((*b)->value < (*b) ->previous->value)
			sb(b);
		while ((*b) -> value > (*a) -> value)
		{
			ra(a, taila);
			rotations++;
		}
		pa(a,b);
		while (rotaions-- > 0)
			rra(a, taila);
	}
}
void	set_values(t_stack **a, int *p)
{
	t_stack *tmp;

	tmp = *a;
	while (tmp)
	{
		tmp ->value = p[tmp ->value];
		tmp = tmp -> previous;
	}
}

void	Medium(t_stack** a, t_stack** taila, t_stack** b, t_stack** tailb)
{
	int	i;
	int	*p;
	int	len;
	int	window;
	t_stack	*tmp;
	
	i = 0;
	len = stack_len(a);
	window = window_size(len);
	tmp = *a;
	p = malloc (len * sizeof(int));
	while (tmp)
	{
		p[i] = tmp ->value;
		i++;
		tmp = tmp ->next;
	}
	sort_p(p);
	set_index(a,p);
	push_to_b(a, taila, b, tailb);
	push_back(a, b);
	set_values(a, p);
} 

void	sort(t_stack** a, t_stack** taila)
{
	t_stack* b;
	t_stack* tailb;
	float disorder;

	b = NULL;
	tailb = NULL;
	disorder = disorder(*a);
	if (!*a)
		return ;
	if (disorder < 0.2)
		Simple(a, taila, &b, &tailb);
	else if (disorder < 0.5)
		Medium();
	else if (disorder >= 0.5)
		Complex();
}
